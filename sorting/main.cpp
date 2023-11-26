#include <iostream>
#include <chrono>
#include <span>
#include <numeric>
#include <iomanip>
#include <random>
#include <algorithm>
#include "binary_search_tree.h"

using clk = std::chrono::high_resolution_clock;

std::string join(const std::span<int> nums, auto ch) {
    return std::accumulate(
            std::next(nums.begin()),
            nums.end(),
            std::to_string(nums[0]),
            [ch](auto s, auto n) {
                return std::move(s) + ch + std::to_string(n);
            });
}

void track_time(auto desc, void (*f)(std::span<int>), std::span<int> nums) {
    auto t = clk::now();
    f(nums);
    const std::chrono::duration<double> span = clk::now() - t;
    std::cout << std::setw(15) << desc << ": ";
    std::cout << "time = " << span.count() << "s" << std::endl;
}

void fill_array(std::span<int> nums) {
    std::random_device rnd;
    std::default_random_engine eng(rnd());
    std::uniform_int_distribution<size_t> dist(1, nums.size());
    std::generate(nums.begin(), nums.end(), [&](){
        return dist(eng);
    });
}

void bubble_sort(std::span<int> nums) {
    for (int i = 0; i < nums.size() - 2; ++i) {
        for (int j = 0; j < nums.size() - 1 - i; ++j) {
            if (nums[j] > nums[j + 1])
                std::swap(nums[j], nums[j + 1]);
        }
    }
}

void selection_sort(std::span<int> nums) {
    for (auto i = nums.begin() ; i < nums.end(); ++i) {
        auto min = std::min_element(i, nums.end());

        // is it lower than the number we currently have?
        if (*min < *i) {
            std::swap(*min, *i);
        }
    }
}

void insertion_sort(std::span<int> nums) {
    for (int i = 1; i < nums.size(); ++i) {
        // take the current value
        auto temp = nums[i];

        // shuffle values greater than ahead of this value
        auto j = i;
        for (; j > 0 && temp < nums[j - 1]; j--) {
            nums[j] = nums[j - 1];
        }

        // put the current value back
        nums[j] = temp;
    }
}

void shell_sort(std::span<int> nums) {
    // determine gap sizes (e.g. 5 2 1)
    for (auto gap = nums.size() / 2; gap > 0; gap /= 2) {
        for (auto start = 0; start < gap; start++) {
            // insertion sort
            for (auto i = start + gap; i < nums.size(); i += gap) {
                // take the current value
                auto temp = nums[i];

                // shuffle values greater than it ahead of this value
                auto j = i;
                for (; j >= gap && temp < nums[j - gap]; j -= gap) {
                    nums[j] = nums[j - gap];
                }

                // insert the value back
                nums[j] = temp;
            }
        }
    }
}

auto split(std::span<int> nums) {
    // assume pivot point is first element
    auto pivot = nums[0];

    // start searching for numbers less than and greater than the pivot
    auto left = 0;
    auto right = nums.size() - 1;

    // keep searching until all elements are in their correct spots
    while (left < right) {
        // move all less than the pivot to the left
        while (pivot < nums[right]) right--;

        // move all greater than the pivot to the right
        while (pivot >= nums[left]) left++;

        // if two were found out of place, swap them
        if (left < right) {
            std::swap(nums[left], nums[right]);
        }
    }

    // now move the pivot between the two sublists
    nums[0] = nums[right];
    nums[right] = pivot;

    // returns the pivot point
    return right;
}

void quick_sort(std::span<int> nums) {
    // assume array is sorted when it is only 0 or 1 element
    if (nums.size() <= 1) return;

    // split the array into two sublists
    // returns the index of the pivot point
    auto pivot = split(nums);

    // sort the left sublist
    quick_sort(nums.subspan(0, pivot));

    // sort the right sublist
    quick_sort(nums.subspan(pivot + 1, nums.size() - pivot - 1));
}

void bst_sort(std::span<int> nums) {
    BST bst;

    for (auto i = 0; i < nums.size(); i++) {
        bst.insert(nums[i]);
    }

    bst.save_array(nums);
}

int main() {

    size_t len = 10;
    for (; len <= 10000; len *= 10) {
        auto nums = new int[len];

        fill_array({nums, len});
        track_time("bubble sort", bubble_sort, {nums, len});
        fill_array({nums, len});
        track_time("selection sort", selection_sort, {nums, len});
        fill_array({nums, len});
        track_time("insertion sort", insertion_sort, {nums, len});
        fill_array({nums, len});
        track_time("shell sort", shell_sort, {nums, len});
        fill_array({nums, len});
        track_time("quick sort", quick_sort, {nums, len});
        fill_array({nums, len});
        track_time("bst sort", bst_sort, {nums, len});

        delete[] nums;
    }

    return 0;
}