// Scoreboard Project / Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

UCLASS()
class SCOREBOARD_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void SetupInputComponent() override;
	void ShowStat();
	void HideStat();

protected:
	virtual void BeginPlay() override;
};
