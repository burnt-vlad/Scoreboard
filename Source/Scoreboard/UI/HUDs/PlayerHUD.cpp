// Scoreboard Project / Fedosov Vladislav

#include "Scoreboard/UI/HUDs/PlayerHUD.h"
#include "Blueprint/UserWidget.h"

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerHUD::ShowStat()
{
	//Creates a score table widget on input start
	if (ScoreboardWidgetClass)
	{
		ScoreboardWidget = CreateWidget<UUserWidget>(GetWorld(), ScoreboardWidgetClass);
		if (ScoreboardWidget) ScoreboardWidget->AddToViewport();
	}
}

void APlayerHUD::HideStat()
{
	if (ScoreboardWidget)
	{
		ScoreboardWidget->RemoveFromParent();
	}
}