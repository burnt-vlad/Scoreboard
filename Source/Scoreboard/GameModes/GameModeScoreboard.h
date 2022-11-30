// Scoreboard Project / Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeScoreboard.generated.h"

class AAIController;

UCLASS()
class SCOREBOARD_API AGameModeScoreboard : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

protected:
	virtual void StartPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Game Mode Properties")
		TSubclassOf<AAIController> AIControllerClass;
	UPROPERTY(EditDefaultsOnly, Category = "Game Mode Properties")
		TSubclassOf<APawn> AIPawnClass;
	UPROPERTY(EditDefaultsOnly, Category = "Game Mode Properties")
		int32 PlayersNum = 6;


private:
	AController* GetRandomController();
	void AddPointsToPlayer(int32 Points, AController* Controller);
	void AddPointsToRandomPlayer();
	void SpawnBots();

	FTimerHandle AddPointsTimer;
};
