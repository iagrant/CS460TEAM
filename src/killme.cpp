Walk the AST depth first
At each node call function that does something depending on the type of the node

// This walks the tree without assistance from other functions
// Calls the build function once it reaches the leaf and recurrsively
// walks the tree similarly to how it is created by yacc bottom-up
void walkTree (ASTnode * parent)
{
    build3AC(parent);
    for (int i = 0; i < parent->child.size(); i++)
    {
        if (parent->child.size() != 0)
        {
            walkTree(parent->child[i]);
        }
    }
}

// This function just does what it needs and then returns
void build3AC (ASTnode * currentNode)
{
    if (currentNode->nodeType == funcN)
    {
        // need to know the frame size
        // ticket counter for the function
        // return type?
    }
    else if (currentNode->nodeType == idN)
    {
        // should just return because will be handled by the operator node
    }
    else if (currentNode->production.compare("EQUALS") == 0)
    {
        // needs to assign "ASSIGN des src"
    }
    else if (currentNode->nodeType == mathN)
    {
        // This side executes before the equals
        // Create temp var for each operator
        // T0 = 4
        // T1 = 5 - T0
        // T2 = 6 * T1
    }
    else if (currentNode->nodeType == forN)
    {
        // create label for iterative statement
        // label has to go above 
    }
    else if (currentNode->nodeType == ifN)
    {

    }
    else if (currentNode->nodeType == whileN)
    {

    }
    else if (currentNode->nodeType == constantN)
    {

    }
    else
        return;
}
