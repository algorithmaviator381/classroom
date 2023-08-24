import GPUtil

gpus = GPUtil.getGPUs()
for gpu in gpus:
    print(f"GPU Name: {gpu.name}")
    print(f"CUDA Cores: {gpu.CUDA_CORES}")
    print("-" * 30)
