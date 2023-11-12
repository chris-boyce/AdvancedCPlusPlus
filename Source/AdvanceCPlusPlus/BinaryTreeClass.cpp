// Chris Boyce 1908671 - Advanced C++ Module 


#include "BinaryTreeClass.h"

void UBinaryTreeClass::Insert(FScoreboardData Value)
{
	if(Root == nullptr) //Checks on the Root Being Null
	{
		Root = NewObject<UBinaryTreeNode>(this);
		Root->Value = Value;
	}
	else //Node isnt Null
	{
		UBinaryTreeNode* CurrentNode = Root; 
		while (CurrentNode) //Recursive Loop
		{
			if(Value.Score < CurrentNode->Value.Score) //Checks is value is Smaller
			{
				if(CurrentNode->LeftChild == nullptr) //Checks if there a left node
				{
					CurrentNode->LeftChild = NewObject<UBinaryTreeNode>(this); //If empty its assigns the left node to it
					CurrentNode->LeftChild->Value = Value; 
					return;
				}
				else //If there is a node it then traverses over to it
				{
					CurrentNode = CurrentNode->LeftChild;
				}
			}
			else //Else it is a Bigger
			{
				if (CurrentNode->RightChild == nullptr) //Checks for right Child
				{
					CurrentNode->RightChild = NewObject<UBinaryTreeNode>(this); //If Empty Assigns the right node
					CurrentNode->RightChild->Value = Value;
					return;
				}
				else //If there is a node it then traverses over to it
				{
					CurrentNode = CurrentNode->RightChild;
				}
			}
		}
	}
}

void UBinaryTreeClass::InOrderTraversal(UBinaryTreeNode* Node, TArray<FScoreboardData>& Result)
{
	if (Node)
	{
		InOrderTraversal(Node->LeftChild, Result);
		Result.Add(Node->Value);
		InOrderTraversal(Node->RightChild, Result);
	}
	
}
void UBinaryTreeClass::ReverseOrderTraversal(UBinaryTreeNode* Node, TArray<FScoreboardData>& Result)
{
	if (Node)
	{
		ReverseOrderTraversal(Node->RightChild, Result);
		Result.Add(Node->Value);
		ReverseOrderTraversal(Node->LeftChild, Result);
	}
}

UBinaryTreeNode* UBinaryTreeClass::OrderedSearch(UBinaryTreeNode* Node, FString SearchString)
{
	if(Node == nullptr)
	{
		return nullptr;
	}
	if(Node->Value.Name == SearchString)
	{
		return Node;
	}
	UBinaryTreeNode* leftResult = OrderedSearch(Node->LeftChild, SearchString);
	UBinaryTreeNode* rightResult = OrderedSearch(Node->RightChild, SearchString);
	
	if (leftResult != nullptr)
	{
		return leftResult;
	}
	else
	{
		return rightResult;
	}
	
	
}

UBinaryTreeNode* UBinaryTreeClass::BinarySearch(UBinaryTreeNode* Node, int SearchInt)
{
	if (Node == nullptr || Node->Value.Score == SearchInt)
	{
		return Node;
	}
	
	if(SearchInt < Node->Value.Score)
	{
		return BinarySearch(Node->LeftChild , SearchInt);
	}
	else
	{
		return BinarySearch(Node->RightChild, SearchInt);
	}
}

