// Scoreboard Project / Fedosov Vladislav

#include "Scoreboard/PlayerControllers/BasePlayerController.h"
#include "Scoreboard/UI/HUDs/PlayerHUD.h"
#include "GameFramework/PlayerState.h"

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("ShowScoreboard", IE_Pressed, this, &ABasePlayerController::ShowStat);
	InputComponent->BindAction("ShowScoreboard", IE_Released, this, &ABasePlayerController::HideStat);
}

void ABasePlayerController::BeginPlay()
{
	if (PlayerState) PlayerState->SetPlayerName("Player");
}

void ABasePlayerController::ShowStat()
{
	const auto PlayerHUD = Cast<APlayerHUD>(GetHUD());
	if (PlayerHUD) PlayerHUD->ShowStat();
}

void ABasePlayerController::HideStat()
{
	const auto PlayerHUD = Cast<APlayerHUD>(GetHUD());
	if (PlayerHUD) PlayerHUD->HideStat();
}