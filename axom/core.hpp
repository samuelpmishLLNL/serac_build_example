#if defined(__CUDACC__)
#define AXOM_HOST_DEVICE __host__ __device__
#define AXOM_HOST __host__
#define AXOM_DEVICE __device__
#else
#define AXOM_HOST_DEVICE
#define AXOM_HOST
#define AXOM_DEVICE
#endif

namespace axom {
  void foo_host();
#if defined(__CUDACC__)
  void foo_device();
  AXOM_HOST_DEVICE void transform(double &);
#endif
}
