// Scoreboard Project / Fedosov Vladislav

#include "Scoreboard/UI/Widgets/PlayerStatWidget.h"
#include "Components/TextBlock.h"

void UPlayerStatWidget::SetPlayerName(const FText& Text)
{
	if (!PlayerNameTextBlock) return;
	PlayerNameTextBlock->SetText(Text);
}

void UPlayerStatWidget::SetPlayerScore(const FText& Text)
{
	if (!PlayerScoreTextBlock) return;
	PlayerScoreTextBlock->SetText(Text);
}
