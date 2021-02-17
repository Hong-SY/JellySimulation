#pragma once

#include "JellyStatus.generated.h"

USTRUCT(Atomic, BlueprintType)
struct FJellyStatus
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 aggression = 50;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 activity = 50;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 reproductivity = 50;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 endurability = 50;
};

