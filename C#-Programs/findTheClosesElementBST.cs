using System;

namespace BST 
{
    public class Solution
    {
        public static int minDiff, minDiffKey;

        public class Node
        {
            public int key;
            public Node left, right;
        }

        public static Node NewNode(int key)
        {
            Node node = new Node();
            node.key = key;
            node.left = node.right = null;
            return (node);
        }

        public static void MaxDifferenceUtility(Node ptr, int k)
        {
            if (ptr == null)
            {
                return;
            }
            if (ptr.key == k)
            {
                minDiffKey = k;
                return;
            }

            if (minDiff > Math.Abs(ptr.key - k))
            {
                minDiff = Math.Abs(ptr.key - k);
                minDiffKey = ptr.key;
            }

            if (k < ptr.key)
            {
                MaxDifferenceUtility(ptr.left, k);
            }
            else
            {
                MaxDifferenceUtility(ptr.right, k);
            }
        }

        public static int MaxDifference(Node root, int k)
        {
            minDiff = 999999;
            minDiffKey = -1;

            MaxDifferenceUtility(root, k);
            return minDiffKey;
        }

        public static void Main(string[] args)
        {
            Node root = NewNode(10);
            root.left = NewNode(9);
            root.right = NewNode(13);
            root.left.left = NewNode(4);
            root.left.right = NewNode(6);
            root.left.right.left = NewNode(8);
            root.left.right.right = NewNode(71);
            root.right.right = NewNode(2);
            root.right.right.left = NewNode(20);

            int k = 18;
            Console.WriteLine(MaxDifference(root, k));
        }
    }
}