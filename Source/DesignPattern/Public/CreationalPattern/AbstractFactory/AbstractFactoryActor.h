// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MonsterBase.h"
#include "GameFramework/Actor.h"
#include "AbstractFactoryActor.generated.h"

UCLASS()
class UMonsterFactory : public UObject
{
	GENERATED_BODY()

public:
	virtual UMonsterSoldier* CreateMonsterSoldier()
	{
		return nullptr;
	}

	virtual UMonsterArcher* CreateMonsterArcher()
	{
		return nullptr;
	}
};

UCLASS()
class UUndeadMonsterFactory: public UMonsterFactory
{
	GENERATED_BODY()

public:
	virtual UMonsterSoldier* CreateMonsterSoldier() override
	{
		return NewObject<UUndeadSkeletonSoldier>();
	}

	virtual UMonsterArcher* CreateMonsterArcher() override
	{
		return NewObject<UUndeadSkeletonArcher>();
	}

};

UCLASS()
class UGoblinMonsterFactory : public UMonsterFactory
{
	GENERATED_BODY()

public:
	virtual UMonsterSoldier* CreateMonsterSoldier() override
	{
		return NewObject<UGoblinSoldier>();
	}

	virtual UMonsterArcher* CreateMonsterArcher() override
	{
		return NewObject<UGoblinArcher>();
	}
};



UCLASS()
class DESIGNPATTERN_API AAbstractFactoryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbstractFactoryActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
