// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProjectBase.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERN_API UProjectBase : public UObject
{
	GENERATED_BODY()
public:
	virtual void ProjectFunction()
	{
		UE_LOG(LogTemp, Warning, TEXT("You Should OverWrite This"));
	}
};


UCLASS()
class UProjectA : public UProjectBase
{
	GENERATED_BODY()
public:
	virtual void ProjectFunction() override
	{
		UE_LOG(LogTemp, Warning, TEXT("Project A Function Called"));
	}
};

UCLASS()
class UProjectB : public UProjectBase
{
	GENERATED_BODY()

public:
	virtual void ProjectFunction() override
	{
		UE_LOG(LogTemp, Warning, TEXT("Project B Function Called"));
	}
};
