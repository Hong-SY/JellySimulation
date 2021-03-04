#pragma once

#include "JellyStatus.generated.h"

USTRUCT(Atomic, BlueprintType)
struct FJellyStatus
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 Aggression;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 Activity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 Reproductivity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 Endurability;
};

