// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeGameModeBase.h"
#include "EscapeCharacter.h"

AEscapeGameModeBase::AEscapeGameModeBase()
{
	DefaultPawnClass = AEscapeCharacter::StaticClass();
}
