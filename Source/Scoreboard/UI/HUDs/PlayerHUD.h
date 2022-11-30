// Scoreboard Project / Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

class UUserWidget;

UCLASS()
class SCOREBOARD_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:
	void ShowStat();
	void HideStat();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget> ScoreboardWidgetClass;

	virtual void BeginPlay() override;

private:
	UUserWidget* ScoreboardWidget = nullptr;
};
