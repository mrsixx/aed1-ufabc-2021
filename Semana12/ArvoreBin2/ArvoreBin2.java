import java.util.Scanner;

class Node{
    private Node father;
    private Node left;
    private Node right;
    private int value;

    //getters e setters
    public Node getFather()
    {
        return this.father;
    }

    public void setFather(Node father)
    {
        this.father = father;
    }

    public Node getLeft()
    {
        return this.left;
    }

    public void setLeft(Node left)
    {
        this.left = left;
    }

    public Node getRight()
    {
        return this.right;
    }

    public void setRight(Node right)
    {
        this.right = right;
    }

    public int getValue()
    {
        return this.value;
    }

    public void setValue(int value)
    {
        this.value = value;
    }

    //constructor
    public Node(int value)
    {
        this.setValue(value);
        this.setLeft(null);
        this.setRight(null);
        this.setFather(null);
    }

    public boolean isLeafNode()
    {
        return this.getLeft() == null && this.getRight() == null;//se não tiver filho a esquerda nem a direita, é folha
    }

    public boolean Full()

    public boolean hasLeft

}

class Tree{
    private Node root;

    //getters e setters
    public Node getRoot()
    {
        return this.root;
    }

    public void setRoot(Node root)
    {
        this.root = root;
    }

    //constructor
    public Tree()
    {
        this.setRoot(null);
    }

    //métodos
    public void Insert(int value)
    {
        Node pai = null, filho = this.getRoot(), novo = new Node(value);

        //encontro a posição de inserção
        while(filho != null)
        {
            pai = filho;
            if(filho.getValue() < value)
                filho = filho.getRight();
            else
                filho = filho.getLeft();
        }

        if(pai != null)
        {//se eu estiver inserindo numa folha da arvore
            novo.setFather(pai);
            if(pai.getValue() > value)//filho da esquerda
              pai.setLeft(novo);
            else
                pai.setRight(novo);
        }
        else//inserindo na raiz
            this.setRoot(novo);
    }

    public Node Remove(int value)
    {
        //procuro a posição
        Node anterior = null, filho = this.getRoot();
        while(filho != null && filho.getValue() != chave)
        {
            anterior = filho;
            if(filho.getValue() < chave)
            {
                filho = filho.getRight();
            }
            else
            {
                filho = filho.getLeft();
            }
        }

        if(filho != null)
        {
            Node subs = new Node(value);
            if(filho.isLeafNode()) // folha
                //apagar
            else if(filho->esquerda != NULL && filho->direita != NULL) // galho completo
                //apagar
            else

        }

        return filho;
    }

    public void PrintPreOrder(Node node)
    {
        if(node != null)
        {
            System.out.print(node.getValue()+ " ");
            this.PrintPreOrder(node.getLeft());
            this.PrintPreOrder(node.getRight());
        }
    }

    public void PrintInOrder(Node node)
    {
        if(node != null)
        {
            this.PrintPreOrder(node.getLeft());
            System.out.print(node.getValue()+ " ");
            this.PrintPreOrder(node.getRight());
        }
    }

    public void PrintPostOrder(Node node)
    {
        if(node != null)
        {
            this.PrintPreOrder(node.getLeft());
            this.PrintPreOrder(node.getRight());
            System.out.print(node.getValue()+ " ");
        }
    }
}


class ArvoreBin2 {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);

        Tree arvore = new Tree();
        String cmd;
        int in = 0;
        while(scan.hasNext())
        {
            cmd = scan.next();
            switch(cmd)
            {
                case "insert":
                    in = scan.nextInt();
                    arvore.Insert(in);
                    break;
                case "delete":
                    in = scan.nextInt();
                    Node removed = arvore.Remove(in);
                    if(removed != null)
                        System.out.println(removed.getValue());
                    break;
                case "pre-order":
                    arvore.PrintPreOrder(arvore.getRoot());
                    System.out.println();
                    break;
                case "in-order":
                    arvore.PrintInOrder(arvore.getRoot());
                    System.out.println();
                    break;
                case "post-order":
                    arvore.PrintPostOrder(arvore.getRoot());
                    System.out.println();
                    break;

            }
        }
    }
}