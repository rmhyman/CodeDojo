#ifndef TREE_H
#define TREE_H

using TreeElement = int;
struct TreeNode
{
	TreeElement element;
	std::shared_ptr<TreeNode> FirstChild;
	std::shared_ptr<TreeNode> NextChild;
};


#endif
