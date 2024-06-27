// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlatform.h"

#include "StructuralPattern/FacadePattern/FacadeBase.h"
#include "StructuralPattern/ProxyPattern/SubjectBase.h"

// Sets default values
ATestPlatform::ATestPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void ATestPlatform::BeginPlay()
{
	Super::BeginPlay();

	Proxy = NewObject<UProxy>();
	if (!Proxy)
	{
		UE_LOG(LogTemp, Warning, TEXT("Proxy fail to create"));
	}


	MyFacade = NewObject<UMyFacadeBase>();

	if (!MyFacade)
	{
		UE_LOG(LogTemp, Warning, TEXT("MyFacade fail to create"));
	}


	Proxy->DoBusiness(10);

	MyFacade->Run();
	

}

// Called every frame
void ATestPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

