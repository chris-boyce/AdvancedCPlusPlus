// Chris Boyce 1908671 - Advanced C++ Module 

#include "ScoreboardManager.h"
#include "LeagueTemplate.h"

AScoreboardManager::AScoreboardManager()
{
	PrimaryActorTick.bCanEverTick = true;
	if(ScoreBoardDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("Data Table imported"));
	}
}

void AScoreboardManager::CreateTemplate()
{
	if(ScrollBox)
	{
		TArray<FScoreboardData> InOrderResult;
		ScoreBoardBinaryTree->ReverseOrderTraversal(ScoreBoardBinaryTree->Root, InOrderResult);

		for (int32 i = 0; i < InOrderResult.Num(); ++i)
		{
			FScoreboardData Value = InOrderResult[i];
			ULeagueTemplate* NewItem = CreateWidget<ULeagueTemplate>(GetWorld(), TemplateWidget);
			NewItem->ChangeText(Value.Name, Value.Score, i);
			ScrollBox->AddChild(NewItem);
		}
		
	}
}

void AScoreboardManager::SearchBinaryTree1(int SearchItem)
{
	UBinaryTreeNode* result = ScoreBoardBinaryTree->OrderedSearch(ScoreBoardBinaryTree->Root , "Christopher");
	UE_LOG(LogTemp, Warning, TEXT("Result Score: %d"), result->Value.Score);
}

void AScoreboardManager::SearchBinaryTree1(FString SearchItem)
{
	UBinaryTreeNode* result = ScoreBoardBinaryTree->BinarySearch(ScoreBoardBinaryTree->Root , 10497);
	UE_LOG(LogTemp, Warning, TEXT("Result Name: %s"), *result->Value.Name);
}



void AScoreboardManager::BeginPlay()
{
	Super::BeginPlay();
	ScoreBoardBinaryTree = NewObject<UBinaryTreeClass>(this);

	if (ScoreBoardDataTable)
	{
		TArray<FName> RowNames = ScoreBoardDataTable->GetRowNames();
		for (FName RowName : RowNames)
		{
			FScoreboardData* DataRow = ScoreBoardDataTable->FindRow<FScoreboardData>(RowName, "");
			if (DataRow)
			{
				FScoreboardData ScoreboardTemp;
				ScoreboardTemp.Name = DataRow->Name;
				ScoreboardTemp.Score = DataRow->Score;
				ScoreBoardBinaryTree->Insert(ScoreboardTemp);
			}
		}
	}
	SearchBinaryTree1("Christopher");
	SearchBinaryTree1(10497);
}


