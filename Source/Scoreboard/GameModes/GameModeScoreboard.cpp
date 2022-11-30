// Scoreboard Project / Fedosov Vladislav

#include "Scoreboard/GameModes/GameModeScoreboard.h"
#include "GameFramework/PlayerState.h"
#include "AIController.h"

//All logic in this gamemode simulates a gameplay in which players receive a certain number of points during the game.

void AGameModeScoreboard::StartPlay()
{
	Super::StartPlay();
	SpawnBots();
	GetWorldTimerManager().SetTimer(AddPointsTimer, this, &AGameModeScoreboard::AddPointsToRandomPlayer, 1.f, true);
}

UClass* AGameModeScoreboard::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	if (InController && InController->IsA<AAIController>())
	{
		return AIPawnClass;
	}
	return Super::GetDefaultPawnClassForController_Implementation(InController);
}

void AGameModeScoreboard::SpawnBots()
{
	if (!GetWorld() || !AIControllerClass) return;
	for (int32 i = 0; i < PlayersNum - 1; ++i)
	{
		FActorSpawnParameters ActorSpawnParameters;
		ActorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		const auto AIController = GetWorld()->SpawnActor<AAIController>(AIControllerClass, ActorSpawnParameters);
		RestartPlayer(AIController);
	}
}

AController* AGameModeScoreboard::GetRandomController()
{
	if (!GetWorld()) return nullptr;
	int32 ControllersNum = GetWorld()->GetNumControllers();
	int32 RandomControllerIndex = FMath::RandRange(0, ControllersNum - 1);
	auto It = GetWorld()->GetControllerIterator();
	return (It + RandomControllerIndex)->IsValid() ? (It + RandomControllerIndex)->Get() : nullptr;
}

void AGameModeScoreboard::AddPointsToPlayer(int32 Points, AController* Controller)
{
	if (Points == 0 || !Controller) return;
	const auto PlayerState = Controller->PlayerState;
	if (!PlayerState) return;
	PlayerState->SetScore(PlayerState->GetScore() + Points);
	int32 Score = PlayerState->GetScore();
	UE_LOG(LogTemp, Warning, TEXT("Score: %i"), Score);
	UE_LOG(LogTemp, Warning, TEXT("ActorName: %s \n"), *(PlayerState->GetName()));
}

void AGameModeScoreboard::AddPointsToRandomPlayer()
{
	AddPointsToPlayer(FMath::RandRange(1, 100), GetRandomController());
}
