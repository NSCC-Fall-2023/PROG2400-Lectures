#include <span>
#include <queue>
#include <numeric>
#include "sorting.h"

void track_time(auto desc, void (*f)(std::span<int>), std::span<int> nums) {
    auto t = clk::now();
    f(nums);
    const std::chrono::duration<double> span = clk::now() - t;
    std::cout << std::setw(15) << desc << ": ";
    std::cout << "time = " << span.count() << "s" << std::endl;
}

std::string join(const std::span<int> nums, auto ch) {
    return std::accumulate(
            std::next(nums.begin()),
            nums.end(),
            std::to_string(nums[0]),
            [ch](auto s, auto n) {
                return std::move(s) + ch + std::to_string(n);
            });
}

void split(std::queue<int>& in, std::queue<int>& out1, std::queue<int>& out2) {
    int num_subfiles = 0;

    int prev = -1;
    while (!in.empty()) {

        // read in record
        int curr = in.front();
        in.pop();

        if (curr < prev) num_subfiles++;

        // write out odds and evens
        if (num_subfiles % 2 == 0) {
            out2.push(curr);
        } else {
            out1.push(curr);
        }

        prev = curr;
    }
}

bool elements_in_column(std::queue<int>& first, std::queue<int>& second, int last) {
    return !first.empty() && (first.front() <= last) &&
            (second.empty() || (second.front() < last) || (first.front() < second.front()));
}

bool elements_in_sublist(std::queue<int>& first, std::queue<int>& second, int last) {
    return !first.empty() && (first.front() >= last);
}

int merge(std::queue<int>& out, std::queue<int>& in1, std::queue<int>& in2) {
    int num_subfiles = 0;

    // who starts the process?
    auto& first = in2.empty() || (in1.front() < in2.front()) ? in1 : in2;
    auto& second = first == in1 ? in2 : in1;

    // keep merging while there are records left
    while (!in1.empty() || !in2.empty()) {

        int last = -1;
        while (elements_in_sublist(first, second, last)) {
            // take records from column while in order
            do {
                last = first.front();
                first.pop();
                out.push(last);
            } while (elements_in_column(first, second, last));

            // when done switch to taking elements from second column
            // if there is none left in second, stay on first
            if (!second.empty()) {
                std::swap(first, second);
            }
        }

        // move to next subfile
        num_subfiles++;
    }

    return num_subfiles;
}

void merge_sort(std::span<int> nums) {

    // copy array to queue
    std::queue<int> merged;
    for (auto num: nums) {
        merged.push(num);
    }

    // merge sort
    std::queue<int> split1, split2;
    auto subfiles = 0;
    do {
        split(merged, split1, split2);

        std::cout << "Split" << std::endl;
        std::cout << "temp1:" << split1 << std::endl;
        std::cout << "temp2:" << split2 << std::endl;

        subfiles = merge(merged, split1, split2);

        std::cout << "Merge" << std::endl;
        std::cout << merged << std::endl;

    } while(subfiles != 1);

    // copy back to array
    int i = 0;
    while (!merged.empty()) {
        nums[i++] = merged.front();
        merged.pop();
    }

}

int main() {

    size_t len = 10;
    for (; len <= 10; len *= 10) {
        auto nums = new int[len];

//        fill_array({nums, len});
//        track_time("bubble sort", bubble_sort, {nums, len});
//        fill_array({nums, len});
//        track_time("selection sort", selection_sort, {nums, len});
//        fill_array({nums, len});
//        track_time("insertion sort", insertion_sort, {nums, len});
//        fill_array({nums, len});
//        track_time("shell sort", shell_sort, {nums, len});
//        fill_array({nums, len});
//        track_time("quick sort", quick_sort, {nums, len});
//        fill_array({nums, len});
//        track_time("bst sort", bst_sort, {nums, len});
        fill_array({nums, len});
        std::cout << join({nums, len}, ',') << std::endl;
        track_time("merge sort", merge_sort, {nums, len});
        std::cout << join({nums, len}, ',') << std::endl;

        delete[] nums;
    }

    return 0;
}