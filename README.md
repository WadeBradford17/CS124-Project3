Wade BradfordWade Bradford
CS124
Project 3
10/14/2022

REPORT:

1.) Information about data set: My data set is a set containing data regarding the stream stastics and profiles of 1000 streamers on Twitch.Tv over the course of one year. There are 11 attributes to each streamer including: streamer name, watch time (minutes), stream time (minutes), peak viewers, average viewers, followers, followers gained, views gained, partnership status, maturity status, and the language the streamer broadcasts in.

2.) How do the depths of the random-order integers compare to the depths of the ordered integers for each tree? Why?
Starting with the Binary Search Trees, the order integer tree has a linear relationship as the depth increased as the integer increased. The random-order Binary Search Tree is a little different as the tree doesn't have only right children, with the depths having no pattern and being anywhere from 0 to 14. The depths of the ordered and random-order AVL Trees are rather similiar, with depths ranging from 0 to 6 in the ordered AVL and 0 to 7 in the random-order AVL. This is due to the balancing property that prevents the generations from having a depth difference greater than 1. In the ordered splay tree, the first five depths are much larger than the ones that follow (99, 50, 26, 13 and 9 respectively). From there, they hover in the 1 to 5 range with the ocassional depth at 6. In the random-order splay tree, the depths simply hover in the 1 to 7 range without the deeper depths at the beginning. This is due to the splaying property that splays the next integer to the root after each insertion.

3.) How do the depths of each custom-data-type (streamer) tree compare to each other?
The depths of each streamer tree vary due to the given properties and limitations of each tree. The streamer binary search tree behaved exactly like the integer binary search tree with the depth increasing with each streamer accessed in the vector, exhibiting a depth of 0 in the front of the vector and 999 at the back. The depths of the AVL tree are balanced, with the deepest depth exhibited being 9, with most hovering in the 5-9 range. It's almost incomparable to the binary search tree as it lacks a linear relationship, instead rebalancing with each insertion. The streamer Splay tree has a similiar first few depths when compared to the integer splay, but scaled up for 1000 rather than 100. The streamer splay tree can be somewhat compared to the AVL, as it relatively balances out after the large depths in the beginning.

4.) Why do the depths of the second custom-data-type Splay Tree make sense?
The depths of the massive (5000) streamer splay tree make sense as the insertion is either splayed to the root or stored as a new depth. In this specific case, the depth is either splayed to 0 or stored with a distinct depth that stabilizies as 1, 2, or 3 following the large depths at the beginning.

ATTACH GRAPHS HERE: 

![Streamer Depths (Binary Search Tree)](https://user-images.githubusercontent.com/112721212/196211897-fa7eb818-22c1-42e7-8ebb-4bb4a891878f.png)

![Streamer Depths (AVL Tree)](https://user-images.githubusercontent.com/112721212/196211968-da883edc-5681-4575-a018-ebe9542d3bcf.png)

![Streamer Depths (Splay Tree)](https://user-images.githubusercontent.com/112721212/196211992-1b40f990-f470-4ceb-8af4-ead24dff6dfd.png)


5.) Compare and contrast the graphs and explain the differences based on what you know about the structure and behavior of the trees. Justify the time complexity of searching the trees based on the results.

The graph of the Streamer Binary Search Tree depths is linear. It inserted the streamer objects in order, meaning that each node had only a right child which caused the depth to increase by 1 with each new node. The time complexity of the binary search tree is O(log n), with auxillary and space complexities of O(1).

The graph of the Streamer AVL Tree is defined by the balancing property. In the tree, the difference between generations (subtrees) cannot be greater than 1, so when insertion occurs the tree rebalances according to this property. The time complexity of the AVL Tree is O(n log n), with auxillary and space complexities of O(1).

The graph of the Streamer Splay Tree is very dissimilar to the other two do to the splaying property. The first few elements have very deep depths until stabilizing for the rest of the tree. The time complexity of the Splay Tree is O(log n) with auxillary and space complexities of O(1).



