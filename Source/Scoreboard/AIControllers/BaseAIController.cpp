// Scoreboard Project / Fedosov Vladislav

#include "Scoreboard/AIControllers/BaseAIController.h"
#include "GameFramework/PlayerState.h"

ABaseAIController::ABaseAIController()
{
	bWantsPlayerState = true;
}

void ABaseAIController::BeginPlay()
{
	if (PlayerState) PlayerState->SetPlayerName("Bot " + PlayerState->GetName());
}