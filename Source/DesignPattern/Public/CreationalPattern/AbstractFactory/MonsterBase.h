// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MonsterBase.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERN_API UMonsterBase : public UObject
{
	GENERATED_BODY()


	virtual void ShowInfo()
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"You Must to OverWrite"));
	}

};


UCLASS()
class UMonsterSoldier: public UMonsterBase
{
	GENERATED_BODY()

public:

	virtual void ShowInfo() override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"SoldierBase"));
	}
	virtual void AttackByMelee()
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"SoldierBase Attack "));
	}
};

UCLASS()
class UMonsterArcher: public UMonsterBase
{
	GENERATED_BODY()

public:
	virtual void ShowInfo() override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"ArcherBase"));
	}
	virtual void AttackByRemote()
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"ArcherBase Attack "));
	}
};


UCLASS()
class UUndeadSkeletonSoldier : public UMonsterSoldier
{
	GENERATED_BODY()

public:
	virtual void ShowInfo() override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"UndeadSkeletonSoldier"));
	}

	virtual void AttackByMelee() override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"UndeadSkeletonSoldier Attack "));
	}
};


UCLASS()
class UGoblinSoldier: public UMonsterSoldier
{
	GENERATED_BODY()

public:
	virtual void ShowInfo() override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"UGoblinSoldier"));
	}

	virtual void AttackByMelee() override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"UGoblinSoldier Attack "));
	}
};

UCLASS()
class UUndeadSkeletonArcher: public UMonsterArcher
{
	GENERATED_BODY()

public:
	virtual void ShowInfo() override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"UUndeadSkeletonArcher"));
	}

	virtual void AttackByRemote() override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"UUndeadSkeletonArcher Attack "));
	}
};

UCLASS()
class UGoblinArcher: public UMonsterArcher
{
	GENERATED_BODY()

public:
	virtual void ShowInfo() override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"UGoblinArcher"));
	}

	virtual void AttackByRemote() override
	{
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"UGoblinArcher Attack "));
	}
};
