
public class BST {

    public int data;
    public BST left, right;

    public BST(int data, BST left, BST right) {
        this.data = data;
        this.left = left;
        this.right = right;
    }

    public BST insert(BST node, int value) {
        BST newNode = new BST(value, null, null);
        if (node == null) {
            node = newNode;
            return node;
        }
        if (value < node.data) {
            node.left = insert(node.left, value);
        }
        else if (value > node.data) {
            node.right = insert(node.right, value);
        }
        return node;
    }

    public bool search(BST node, int value) {
        if (node == null) {
            return false;
        }

        if (value < node.data) {
            search(node.left, value);
        }
        else if (value > node.data) {
            search(node.right, value);
        }
        else {
            return true;
        }
    }

    public int getHeight(BST node) {
        if (node == null) {
            return 0;
        }
        return 1 + Math.max(getHeight(node.left), GetHeight(node.right));
    }

    public int getMin(BST node) {
        if (node == null) {
            return -1;
        }
        if (node.left == null) {
            return node.data;
        }
        return getMin(node.left);
    }

    public int getMax(BST node) {
        if (node == null) {
            return -1;
        }
        if (node.right == null) {
            return node.data;
        }
        return getMax(node.right);
    }

    public void printBFS(BST node) {
        Deque<Integer> queue = new ArrayDeque<>();
        BST current;
        queue.addLast(node);

        while (!queue.isEmpty()) {
            current = queue.removeFirst();
            if (current != null) {
                System.out.println(current.data + " ");
                if (current.left != null) {
                    queue.addLast(current.left);
                }
                if (current.right != null) {
                    queue.addLast(current.right);
                }
            }
        }
    }

    public boolean isBST(BST node) {
        return isBetween(node, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private boolean isBetween(BST node, int min, int max) {
        if (node == null) {
            return true;
        }
        else if (node.data < min || node.data > max) {
            return false;
        }
        return isBetween(node.left, min, node.data) && isBetween(node.right, node.data, max);
    }

}



