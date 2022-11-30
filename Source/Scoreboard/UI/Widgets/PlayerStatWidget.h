// Scoreboard Project / Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatWidget.generated.h"

class UTextBlock;

UCLASS()
class SCOREBOARD_API UPlayerStatWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
		UTextBlock* PlayerNameTextBlock;
	UPROPERTY(meta = (BindWidget))
		UTextBlock* PlayerScoreTextBlock;

public:
	void SetPlayerName(const FText& Text);
	void SetPlayerScore(const FText& Text);
};
