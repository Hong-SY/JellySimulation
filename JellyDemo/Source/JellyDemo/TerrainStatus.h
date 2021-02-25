#pragma once

#include "TerrainStatus.generated.h"

USTRUCT(Atomic, BlueprintType)
struct FTerrainStatus
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        FString Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 ResourceAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 ResourceMaxAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float ResourceRegenerationSpeed;
};

