// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MonsterPrototype.generated.h"

/**
 * 
 */
//����ԭ���ࡪ������
UCLASS(Abstract)
class PROJECTMODE_API UMonsterPrototype : public UObject
{
	GENERATED_BODY()
public:
	//��¡����
	virtual UMonsterPrototype* Clone() {
		UE_LOG(LogTemp, Error, TEXT("Please implement this!"));
		return nullptr;
	}
	//չʾ��Ϣ
	virtual void ShowInfo() {
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s [Health]%d,[Speed]%d"), *this->GetName(), m_Health, m_Speed);
	}
protected:
	int32 m_Health = 100;
	int32 m_Speed = 30;
};
//�����ԭ���ࡪ��Ghost
UCLASS(Blueprintable,BlueprintType)
class PROJECTMODE_API UGhost :public UMonsterPrototype 
{
	GENERATED_BODY()
public:
	virtual UMonsterPrototype* Clone() override {
		UGhost* CloneIns = NewObject<UGhost>();
		CloneIns->m_Health = m_Health;
		CloneIns->m_Speed = m_Speed;
		return CloneIns;
	}
};
//�����ԭ���ࡪ��Devil
UCLASS(Blueprintable, BlueprintType)
class PROJECTMODE_API UDevil :public UMonsterPrototype
{
	GENERATED_BODY()
public:
	UDevil()
	{
		m_Health = 120;
		m_Speed = 20;
	}
	virtual UMonsterPrototype* Clone() override {
		UDevil* CloneIns = NewObject<UDevil>();
		CloneIns->m_Health = m_Health;
		CloneIns->m_Speed = m_Speed;
		CloneIns->m_Attack = m_Attack;
		return CloneIns;
	}
	virtual void ShowInfo() override {
		UE_LOG(LogTemp, Warning, TEXT(__FUNCTION__"%s [Health]%d,[Speed]%d,[Attack]%d"), *this->GetName(), m_Health, m_Speed, m_Attack);
	}
protected:
	int32 m_Attack = 100;
};
//�����ࡪ������������
UCLASS(Blueprintable, BlueprintType)
class PROJECTMODE_API UMonsterSpawner :public UObject
{
	GENERATED_BODY()
public:
	//�����¹���ʹ��ģ�壬�����ظ�
	template<class T>
	T* SpawnMonster() {
		return NewObject<T>();
	}
	//��¡����
	UMonsterPrototype* SpawnMosnter(UMonsterPrototype* pMonsterClass)
	{
		return pMonsterClass->Clone();
	}
};
//����
UCLASS()
class PROJECTMODE_API AMonsterSpawnerActor :public AActor
{
	GENERATED_BODY()
public:
	void BeginPlay() override
	{
		//��������
		UMonsterSpawner* MonsterSpawner = NewObject<UMonsterSpawner>();
		//��һ�δ���Ghost
		UGhost* Ghost = MonsterSpawner->SpawnMonster<UGhost>();
		//��¡Ghost
		UGhost* Ghost_Copy1 = Cast<UGhost>(MonsterSpawner->SpawnMosnter(Ghost));
		Ghost->ShowInfo();
		Ghost_Copy1->ShowInfo();

		//����Devil
		UDevil* Devil = MonsterSpawner->SpawnMonster<UDevil>();;
		//��¡Devil
		UDevil* Devil_Copy1 = Cast<UDevil>(MonsterSpawner->SpawnMosnter(Devil));
		Devil->ShowInfo();
		Devil_Copy1->ShowInfo();

	}
};
