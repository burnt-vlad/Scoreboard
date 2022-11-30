 // Scoreboard Project / Fedosov Vladislav

#include "Scoreboard/UI/Widgets/ScoreboardWidget.h"
#include "GameFramework/PlayerState.h"
#include "Scoreboard/UI/Widgets/PlayerStatWidget.h"
#include "Components/VerticalBox.h"

void UScoreboardWidget::NativeOnInitialized()
{
	UpdatePlayersStats();
	CreateUpdateTimer();
	return Super::NativeOnInitialized();
}

void UScoreboardWidget::GetPlayersStates(TArray<APlayerState*>& States)
{
	//Get all player states from the level using an iterator
	if (!GetWorld()) return;
	for (auto It = GetWorld()->GetControllerIterator(); It; ++It)
	{
		States.Emplace((It->Get())->PlayerState);
	}
}

void UScoreboardWidget::UpdatePlayersStats()
{
	//Creates a container of PlayerStates, sorts them by the score and creates a widget for each
	if (!PlayersStatBox) return;
	PlayersStatBox->ClearChildren();
	TArray<APlayerState*> States;
	GetPlayersStates(States);
	SortPlyerStates(States);
	for (auto& Elem : States)
	{
		//Range-based for loop that creates a score widget for each PlayerState in game
		if (!Elem) continue;
		const auto PlayerStatWidget = CreateWidget<UPlayerStatWidget>(GetWorld(), PlayerStatWidgetClass);
		if (!PlayerStatWidget) continue;

		PlayerStatWidget->SetPlayerName(FText::FromString(Elem->GetPlayerName()));
		PlayerStatWidget->SetPlayerScore(FText::FromString(FString::FromInt(Elem->GetScore())));
		PlayersStatBox->AddChild(PlayerStatWidget);
	}
}

void UScoreboardWidget::SortPlyerStates(TArray<APlayerState*>& States)
{
	//Sorting the array by score using Algo::Sort and lambda-function
	Algo::Sort(States, [](const APlayerState* S1, const APlayerState* S2)
		{
			return S1->GetScore() > S2->GetScore();
		});
}

void UScoreboardWidget::CreateUpdateTimer()
{
	//Updates player score stats every 0.7 seconds if the stats widget is created
	if (!GetWorld()) return;
	FTimerHandle UpdateTimer;
	GetWorld()->GetTimerManager().SetTimer(UpdateTimer, this, &UScoreboardWidget::UpdatePlayersStats, 0.5f, true);
}
