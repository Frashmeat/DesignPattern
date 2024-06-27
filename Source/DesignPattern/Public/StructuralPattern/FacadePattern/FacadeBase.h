// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MySubSystemBase.h"
#include "UObject/NoExportTypes.h"
#include "FacadeBase.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERN_API UFacadeBase : public UObject
{
	GENERATED_BODY()

	virtual void Run()
	{
		
	}
};


UCLASS()
class UMyFacadeBase : public UFacadeBase
{
	GENERATED_BODY()

public:
	UMyFacadeBase()
	{

		SoundSubSystem = NewObject<USoundSubSystem>();
		ActionSubSystem = NewObject<UActionSubSystem>();
		AnimationSubSystem = NewObject<UAnimationSubSystem>();


	}
	virtual void Run() override
	{
		UE_LOG(LogTemp, Warning, TEXT("UMyFacadeBase : Run"));
		AnimationSubSystem->Run();
		SoundSubSystem->Run();
		ActionSubSystem->Run();
	}
private:
	UMySubSystemBase* AnimationSubSystem;
	UMySubSystemBase* SoundSubSystem;
	UMySubSystemBase* ActionSubSystem;
};
