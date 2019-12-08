// Copyright(c) 2019 Daniel Marshall
// SPDX-License-Identifier: MIT


#include "EscapeGameModeBase.h"
#include "EscapeCharacter.h"

AEscapeGameModeBase::AEscapeGameModeBase()
{
	DefaultPawnClass = AEscapeCharacter::StaticClass();
}
