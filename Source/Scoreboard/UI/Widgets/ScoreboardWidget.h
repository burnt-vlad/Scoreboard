// Scoreboard Project / Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreboardWidget.generated.h"

class UVerticalBox;

UCLASS()
class SCOREBOARD_API UScoreboardWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

protected:
	UPROPERTY(meta = (BindWidget))
		UVerticalBox* PlayersStatBox;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget>PlayerStatWidgetClass;

private:
	void GetPlayersStates(TArray<APlayerState*>& States);
	void UpdatePlayersStats();
	void SortPlyerStates(TArray<APlayerState*>& States);
	void CreateUpdateTimer();
};
