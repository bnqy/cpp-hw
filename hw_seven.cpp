#include <iostream>

struct coreLeaves
{
    int san;
    coreLeaves* on;
    coreLeaves* sol;
    coreLeaves(int iii) : san(iii), sol(0), on(0)
    {};
};

coreLeaves* alterLeaves(int san) 
{
    return new coreLeaves(san);
}

coreLeaves* treelike(coreLeaves* tamr, int san)
{
    if (!tamr) 
    {
        tamr = alterLeaves(san);
        return tamr;
    }

    if (san < tamr->san)
    {
        if (!tamr->sol)
        {
            tamr->sol = alterLeaves(san);
        }
        else
        {
            treelike(tamr->sol, san); 
        }
    }
    if (san > tamr->san)
    {
        if (!tamr->on)
        {
            tamr->on = alterLeaves(san);
        }
        else
        {
            treelike(tamr->on, san);
        }
    }
    return tamr;

}

void coutLeaves(coreLeaves* tamr)
{
    if (tamr)
    {
        coutLeaves(tamr->sol);
        if (!tamr->sol && !tamr->on)
            std::cout << tamr->san << std::endl;
        coutLeaves(tamr->on);
    }
}

int main()
{
    int tree;
    std::cin >> tree;
    coreLeaves* treeLike = nullptr;
    if (tree != 0)
        treeLike = new coreLeaves(tree);
    while (tree != 0)
    {
        treelike(treeLike, tree);
        std::cin >> tree;
    }
    coutLeaves(treeLike);
    return 0;
}

