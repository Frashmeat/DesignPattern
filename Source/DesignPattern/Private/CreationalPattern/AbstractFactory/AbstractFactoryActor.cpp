// Fill out your copyright notice in the Description page of Project Settings.


#include "CreationalPattern/AbstractFactory/AbstractFactoryActor.h"

// Sets default values
AAbstractFactoryActor::AAbstractFactoryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAbstractFactoryActor::BeginPlay()
{
	Super::BeginPlay();
	
	UMonsterFactory* UndeadMonsterFactory = NewObject<UUndeadMonsterFactory>();
	UMonsterArcher * UndeadMonsterArcher = UndeadMonsterFactory->CreateMonsterArcher();
	UndeadMonsterArcher->ShowInfo();
	UndeadMonsterArcher->AttackByRemote();
	UMonsterSoldier* UndeadMonsterSoldier = UndeadMonsterFactory->CreateMonsterSoldier();
	UndeadMonsterSoldier->ShowInfo();
	UndeadMonsterSoldier->AttackByMelee();

	UMonsterFactory* GoblinMonsterFactory = NewObject<UGoblinMonsterFactory>();
	UMonsterArcher* GoblinMonsterArcher = GoblinMonsterFactory->CreateMonsterArcher();
	GoblinMonsterArcher->ShowInfo();
	GoblinMonsterArcher->AttackByRemote();
	UMonsterSoldier* GoblinMonsterSoldier = GoblinMonsterFactory->CreateMonsterSoldier();
	GoblinMonsterSoldier->ShowInfo();
	GoblinMonsterSoldier->AttackByMelee();



}

// Called every frame
void AAbstractFactoryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

