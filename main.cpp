/*
 * Wade Bradford
 * CS 124
 * Project 3
 */

using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include "Streamer.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "SplayTree.h"
#include <algorithm>

int main() {

    vector<Streamer> streamers;
    string fn = "../twitchdata-update.csv";
    cout << endl;

    // reads file and stores into vector
    if (readDataFromFile(fn, streamers)) {
        cout << streamers.size() << " steamers read from file" << std::endl;
        string firstName = streamers.front().getStreamerName();
        cout << "The first streamer read was " << firstName << endl;
        string lastName = streamers.back().getStreamerName();
        cout << "The last streamer read was " << lastName << endl;
    }
    else {
        cout << "Something went wrong." << endl;
    }

    cout << endl;

    /* Example of writing out to a file
    ofstream outFile;
    outFile.open("../data/example-output.txt");
    for (int i = 999; i >= 0; --i) {
        outFile << i << endl;
    }
    outFile.close();
    */

    // integer trees for 1 to 100 in order
    BinarySearchTree<int> intBST;
    AVLTree<int> intAVL;
    SplayTree<int> intSplay;

    // int depth for find method
    int depthCount;

    // loop to insert ints 1 to 100 in order
    for (int i = 1; i < 101; i++) {
        intBST.add(i);
        intAVL.add(i);
        intSplay.add(i);
    }

    // loops to find each integer in order and record the depths to a file
    ofstream inOrderDepthsBST;
    inOrderDepthsBST.open("../inOrderDepthsBST.txt");
    for (int i = 1; i < 101; i++) {
        intBST.find(i, depthCount);
        inOrderDepthsBST << depthCount << endl;
    }
    inOrderDepthsBST.close();

    ofstream inOrderDepthsAVL;
    inOrderDepthsAVL.open("../inOrderDepthsAVL.txt");
    for (int i = 1; i < 101; i++) {
        intAVL.find(i, depthCount);
        inOrderDepthsAVL << depthCount << endl;
    }
    inOrderDepthsAVL.close();

    ofstream inOrderDepthsSplay;
    inOrderDepthsSplay.open("../inOrderDepthsSplay.txt");
    for (int i = 1; i < 101; i++) {
        intSplay.find(i,depthCount);
        inOrderDepthsSplay << depthCount << endl;
    }
    inOrderDepthsSplay.close();


    // check for understanding 1 (testing print returns and depth accuracy)
    cout << "Searching for 0: Found = " << boolalpha << intBST.find(0, depthCount) << ", Depth = " << depthCount << endl;
    cout << "Searching for 101: Found = " << boolalpha << intBST.find(101, depthCount) << ", Depth = " << depthCount << endl;
    cout << "Searching for 102: Found = " << boolalpha << intBST.find(102, depthCount) << ", Depth = " << depthCount << endl;


    // loop to create random int vector
    vector <int> intVector;
    for (int i = 1; i < 101; i++) {
        intVector.push_back(i);
    }
    random_shuffle(intVector.begin(), intVector.end());

    // random integer trees 1 to 100
    BinarySearchTree<int> randBST;
    AVLTree<int> randAVL;
    SplayTree<int> randSplay;

    // loop to insert ints 1 to 100 randomly
    for (int i = 1; i < 101; i++) {
        randBST.add(intVector[i]);
        randAVL.add(intVector[i]);
        randSplay.add(intVector[i]);
    }

    // loops to find each integer in order and record the depths to a file
    ofstream randomDepthsBST;
    randomDepthsBST.open("../randomDepthsBST.txt");
    for (int i = 1; i < 101; i++) {
        randBST.find(i, depthCount);
        randomDepthsBST << depthCount << endl;
    }
    randomDepthsBST.close();

    ofstream randomDepthsAVL;
    randomDepthsAVL.open("../randomDepthsAVL.txt");
    for (int i = 1; i < 101; i++) {
        randAVL.find(i, depthCount);
        randomDepthsAVL << depthCount << endl;
    }
    randomDepthsAVL.close();

    ofstream randomDepthsSplay;
    randomDepthsSplay.open("../randomDepthsSplay.txt");
    for (int i = 1; i < 101; i++) {
        randSplay.find(i,depthCount);
        randomDepthsSplay << depthCount << endl;
    }
    randomDepthsSplay.close();

    // trees of custom data type (streamer)
    BinarySearchTree<Streamer> streamerBST;
    AVLTree<Streamer> streamerAVL;
    SplayTree<Streamer> streamerSplay;

    // loop to add streamer objects into trees
    for (int i = 0; i < 1000; i++) {
        streamerBST.add(streamers[i]);
        streamerAVL.add(streamers[i]);
        streamerSplay.add(streamers[i]);
    }

    // loops to find each streamer in order and record the depths to a file
    ofstream streamerInOrderDepthsBST;
    streamerInOrderDepthsBST.open("../streamerInOrderDepthsBST.txt");
    for (int i = 0; i < 1000; i++) {
        streamerBST.find(streamers[i], depthCount);
        streamerInOrderDepthsBST << depthCount << endl;
    }
    streamerInOrderDepthsBST.close();

    ofstream streamerInOrderDepthsAVL;
    streamerInOrderDepthsAVL.open("../streamerInOrderDepthsAVL.txt");
    for (int i = 0; i < 1000; i++) {
        streamerAVL.find(streamers[i], depthCount);
        streamerInOrderDepthsAVL << depthCount << endl;
    }
    streamerInOrderDepthsAVL.close();

    ofstream streamerInOrderDepthsSplay;
    streamerInOrderDepthsSplay.open("../streamerInOrderDepthsSplay.txt");
    for (int i = 0; i < 1000; i++) {
        streamerSplay.find(streamers[i], depthCount);
        streamerInOrderDepthsSplay << depthCount << endl;
    }
    streamerInOrderDepthsSplay.close();


    // additional splay tree
    SplayTree<Streamer> massiveSplay;

    // loop for 1000 streamers
    for (int i = 0; i < 1000; i++) {
        massiveSplay.add(streamers[i]);
    }

    // loop for five times in a row
    ofstream massiveStreamerDepthsSplay;
    massiveStreamerDepthsSplay.open("../massiveStreamerDepthsSplay.txt");
    for (int i = 0; i < 1000; i++) {
        // 1
        massiveSplay.find(streamers[i],depthCount);
        massiveStreamerDepthsSplay << depthCount << endl;
        // 2
        massiveSplay.find(streamers[i],depthCount);
        massiveStreamerDepthsSplay << depthCount << endl;
        // 3
        massiveSplay.find(streamers[i],depthCount);
        massiveStreamerDepthsSplay << depthCount << endl;
        // 4
        massiveSplay.find(streamers[i],depthCount);
        massiveStreamerDepthsSplay << depthCount << endl;
        // 5
        massiveSplay.find(streamers[i],depthCount);
        massiveStreamerDepthsSplay << depthCount << endl;
    }
    massiveStreamerDepthsSplay.close();

}
