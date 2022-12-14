# array

## 1. Two Sum (Incapable)
### Solution
暴力法，双层循环遍历vector，求解和为target的两个元素的下标；时间复杂度O(n^2)

### Standard Solution
暴力法的时间复杂度较高的原因是寻找 target - x 的时间复杂度过高。因此，我们需要一种更优秀的方法，能够快速寻找数组中是否存在目标元素。如果存在，我们需要找出它的索引。

使用哈希表，可以将寻找 target - x 的时间复杂度从 O(N) 降低到 O(1)。

这样我们创建一个哈希表，对于每一个 x，我们首先查询哈希表中是否存在 target - x，然后将 x 插入到哈希表中，即可保证不会让 x 和自己匹配。


## 16. 3Sum Closest (Incapable)
### Solution
暴力法：遍历vector，当遍历到位置i，则该问题可转化为剩余数中和最接近 target - nums[i]；继续遍历剩余元素，当遍历到位置j，则该问题可转化为剩余书中值最接近 target - nums[i] - nums[j]的数；
依次递归，即可求解

**超出时间限制-_-**

### Standard Solution
我们首先考虑枚举第一个元素 a，对于剩下的两个元素 b 和 c，我们希望它们的和最接近 target−a 。对于 b 和 c，如果它们在原数组中枚举的范围（既包括下标的范围，也包括元素值的范围）没有任何规律可言，那么我们还是只能使用两重循环来枚举所有的可能情况。因此，我们可以考虑对整个数组进行升序排序，这样一来：

当我们知道了 b 和 c 可以枚举的下标范围，并且知道这一范围对应的数组元素是有序（升序）的，那么我们是否可以对枚举的过程进行优化呢？

答案是可以的。借助双指针，我们就可以对枚举的过程进行优化。我们用 pb 和 pc 分别表示指向 b 和 c 的指针，初始时，pb指向位置 i+1，即左边界；pc指向位置 n−1，即右边界。
在每一步枚举的过程中，我们根据a+b+c与target的大小关系来移动 pb 和 pc。

#### 小优化
1. 当枚举的a+b+c=target时，可以直接返回target
2. 当我们枚举 a,b,c 中任意元素并移动指针时，可以直接将其移动到下一个与这次枚举的不相同的元素，从而减少枚举的次数

### Error (2 times accept)
1. 没有对数组进行排序
2. while的子循环中没有考虑数组下标是否越界


## 4. Median of Two Sorted Arrays (Incapable)
### Solution
求2个正序数组的中位数，即将2个正序数组合并排序后，求合并后数组的中位数。

我们可以利用有序的特性，使用双指针遍历两个数组，并根据当前指针对应值的大小情况，移动指针，当总的移动次数为 (m+n-1)/2 时，即可求解中位数

### Error (3 times accept)
1. 整数的除法默认返回整数，没有考虑到返回值为double的情况
2. 当总移动次数为 (m+n-1)/2，且2个数组都没有遍历完时，中位数不是简单的`nums1[i] + nums2[j]`，需要同时比较nums1[i+1] 和 nums2[j+1]
3. 当总移动次数为 (m+n-1)/2，且2个数组中某个已遍历完时，计算中位数索引出错

### Tips
* 写完之后，代入所有case，重新过一遍代码

**时间复杂度过高为O(m+n)，题目要求O(log(m+n))**

### Standard Solution
根据中位数的定义，当 m+n 是奇数时，中位数是两个有序数组中的第 (m+n)/2+1 个元素，当 m+n 是偶数时，中位数是两个有序数组中的第 (m+n)/2 个元素和第 (m+n)/2+1 个元素的平均值。因此，这道题可以转化成寻找两个有序数组中的第 k 小的数，其中 k 为 (m+n)/2 或 (m+n)/2+1.

假设两个有序数组分别是 A 和 B。要找到第 k 个元素，我们可以比较 A[k/2−1] 和 B[k/2−1]，其中 / 表示整数除法。由于 A[k/2−1] 和 B[k/2−1] 的前面分别有 A[0 .. k/2−2] 和 B[0 .. k/2−2]，即 k/2−1 个元素，对于 A[k/2−1] 和 B[k/2−1] 中的较小值，最多只会有 (k/2−1)+(k/2−1)≤k−2 个元素比它小，那么它就不能是第 k 小的数了。

因此我们可以归纳出三种情况：
1. 如果 A[k/2−1] < B[k/2−1]，则比 A[k/2−1] 小的数最多只有 A 的前 k/2−1 个数和 B 的前 k/2−1 个数，即比 A[k/2−1] 小的数最多只有 k−2 个，因此 A[k/2−1] 不可能是第 k 个数，A[0] 到 A[k/2−1] 也都不可能是第 k 个数，可以全部排除。
2. 如果 A[k/2−1]>B[k/2−1]，则可以排除 B[0] 到 B[k/2−1]。
3. 如果 A[k/2−1]=B[k/2−1]，则可以归入第一种情况处理。

可以看到，比较 A[k/2−1] 和 B[k/2−1] 之后，可以排除 k/2 个不可能是第 k 小的数，查找范围缩小了一半。同时，我们将在排除后的新数组上继续进行二分查找，并且根据我们排除数的个数，减少 k 的值，这是因为我们排除的数都不大于第 k 小的数。

有以下三种情况需要特殊处理：
1. 如果 A[k/2−1] 或者 B[k/2−1] 越界，那么我们可以选取对应数组中的最后一个元素。在这种情况下，我们必须根据排除数的个数减少 k 的值，而不能直接将 k 减去 k/2。
2. 如果一个数组为空，说明该数组中的所有元素都被排除，我们可以直接返回另一个数组中第 k 小的元素。
3. 如果 k=1，我们只要返回两个数组首元素的最小值即可。

### Tips
* 注意偏移量的计算（ps：偏移量计算经常错）


## 11. Container With Most Water (Incapable)
### Solution
当前问题为：求2个点i,j，使其容积(j - i) * min(height[i], height[j])为数组中的最大值

通过上述公式，对暴力法进行优化；主循环遍历数组，当遍历到位置i时，副循环遍历数组，求解min(height[i], height[j]) = min(height[i])时，对应的容积最大值；依次下去，直至主循环结束。
时间复杂度还是O(n^2)；还不如不优化-_-

### Standard Solution
使用双指针，双指针代表的是可以作为容器边界的所有位置的范围。在一开始，双指针指向数组的左右边界，表示 数组中所有的位置都可以作为容器的边界，因为我们还没有进行过任何尝试。在这之后，我们每次将对应的数字较小的那个指针 往 另一个指针 的方向移动一个位置，就表示我们认为 这个指针不可能再作为容器的边界了。

证明如下：
考虑第一步，假设当前左指针和右指针指向的数分别为 x 和 y，不失一般性，我们假设 x ≤ y。同时，两个指针之间的距离为 t。那么，它们组成的容器的容量为：min(x,y) ∗ t= x ∗ t
我们可以断定，如果我们保持左指针的位置不变，那么无论右指针在哪里，这个容器的容量都不会超过 x ∗ t 了。注意这里右指针只能向左移动，因为 我们考虑的是第一步，也就是 指针还指向数组的左右边界的时候。
我们任意向左移动右指针，指向的数为 y1，两个指针之间的距离为 t1，那么显然有 t1 < t，并且 min⁡(x,y1) ≤ min⁡(x,y)：

* 如果 y1 ≤ y，则 min⁡(x,y1) ≤ min⁡(x,y)
* 如果 y1 > y, 则 min⁡(x,y1) = x = min⁡(x,y)

因此：min(x,y1) * t1 < min(x,y) * t
即无论我们怎么移动右指针，得到的容器的容量都小于移动前容器的容量。也就是说，这个左指针对应的数不会作为容器的边界了，那么我们就可以丢弃这个位置，将左指针向右移动一个位置，此时新的左指针于原先的右指针之间的左右位置，才可能会作为容器的边界。这样以来，我们将问题的规模减小了 1，被我们丢弃的那个位置就相当于消失了。此时的左右指针，就指向了一个新的、规模减少了的问题的数组的左右边界，因此，我们可以继续像之前那样考虑这个问题，直至左右指针相遇

## 15. 3Sum
### Solution
先对数组进行排序，然后主循环遍历数组，当遍历到位置i时，双指针遍历后续数组[j, k]，根据nums[i] + nums[j] + nums[k]的大小，移动其中的指针，直至指针相遇；重复上述步骤，直至主循环遍历完毕；
遍历过程中，需要过滤重复值，避免得到相同的结果

### Error (1 times accept)
1. 指针移动时，边界范围考虑不全，导致跨界出错


## 18. 4Sum
### Solution
使用和题**15. 3Sum**一样的算法；首先对数组进行排序，然后主循环遍历数组，当遍历到位置a时，此时即求存在b,c,d，使得 nums[b] + nums[c] + nums[d] = target - nums[a]，则问题转化为了题**15. 3Sum**的三数之和；重复上述步骤，直至主循环遍历完毕；
遍历过程中，需要过滤重复值，避免得到相同的结果

### Error (1 times accept)
1. 整型越界`nums[a] + nums[a+1] + nums[a+2] + nums[a+3]`，需要注意题目中整数的范围

### Tips
* 一些小优化也有助于提升性能，比如排序数组当前位置的4元祖minimum > target，则可以break；4元祖maximum < target，则可以continue。

## 27. Remove Element
### Solution
使用头尾双指针法，头指针遍历数组，当其指向的元素nums[left] == val时，则交换头尾指针的元素值，并移动尾指针，直至头尾指针相遇。


## 35. Search Insert Position
### Solution
使用二分法遍历数组，直至找到target对应的合适位置

## 26. Remove Duplicates from Sorted Array
### Solution
使用快慢双指针法，快指针遍历数组，当nums[fast] != nums[slow]时，nums[++slow] = nums[fast]，直至遍历结束。

## 31. Next Permutation
### Solution
从后向前遍历数组，存在如下情况：
* nums[i] <= num[i-1], 继续向前遍历
* nums[i] > num[i-1], 则遍历后续[i, n)数组，查找 > nums[i-1] 的最小值，并交换；然后翻转[i, n)中的元素
即可解决该问题

### Error (1 times accept)
1. 存在相同元素的排列，处理错误: [1,5,1] 的下一个排列不是 [1,1,5]，而是[5,1,1]；`[[1,1,5], [1,5,1], [5,1,1]]`