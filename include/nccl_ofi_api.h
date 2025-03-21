/*
 * Copyright (c) 2017-2022, NVIDIA CORPORATION. All rights reserved.
 * Copyright (c) 2022-2023 Amazon.com, Inc. or its affiliates. All rights reserved.
 */

#ifndef NET_OFI_API_H_
#define NET_OFI_API_H_

#include <nccl/err.h>
#include <nccl/net.h>

struct nccl_ofi_properties;

ncclResult_t nccl_net_ofi_init(ncclDebugLogger_t logFunction);
ncclResult_t nccl_net_ofi_devices(int *ndev);
ncclResult_t nccl_net_ofi_get_properties(int dev, struct nccl_ofi_properties *ofi_properties);
ncclResult_t nccl_net_ofi_listen(int dev, void *handle, void **listenComm);
ncclResult_t nccl_net_ofi_listen_v4(int dev, void* handle, void** listenComm);
ncclResult_t nccl_net_ofi_connect(int dev, void* handle, void** sendComm);
ncclResult_t nccl_net_ofi_connect_v4(int dev, void* handle, void** sendComm);
ncclResult_t nccl_net_ofi_accept(void *listenComm, void **recvComm);
ncclResult_t nccl_net_ofi_accept_v4(void* listenComm, void** recvComm);
ncclResult_t nccl_net_ofi_regMr_v7(void *comm, void *data, int size, int type,
				   void **mhandle);
ncclResult_t nccl_net_ofi_regMr(void *comm, void *data, size_t size, int type,
				void **mhandle);
ncclResult_t nccl_net_ofi_regMrDmaBuf(void* comm, void* data, size_t size, int type, uint64_t offset, int fd, void** mhandle);
ncclResult_t nccl_net_ofi_deregMr(void *comm, void *mhandle);
ncclResult_t nccl_net_ofi_isend(void *sendComm, void* data, int size, int tag, void *mhandle, void** request);
ncclResult_t nccl_net_ofi_isend_v4(void* sendComm, void* data, int size, void* mhandle, void** request);
ncclResult_t nccl_net_ofi_isend_v9(void *sendComm, void* data, size_t size, int tag, void *mhandle, void** request);
ncclResult_t nccl_net_ofi_irecv(void* recvComm, int n, void** buffers, int* sizes, int *tags, void** mhandles, void** request);
ncclResult_t nccl_net_ofi_irecv_v4(void* recvComm, void* data, int size, void* mhandle, void** request);
ncclResult_t nccl_net_ofi_irecv_v9(void* recvComm, int n, void** buffers, size_t* sizes, int *tags, void** mhandles, void** request);
ncclResult_t nccl_net_ofi_test(void *request, int *done, int *size);
ncclResult_t nccl_net_ofi_iflush(void* recvComm, int n, void** buffers, int* sizes, void** mhandles, void** request);
ncclResult_t nccl_net_ofi_flush_v3(void* recvComm, void* data, int size, void* mhandle);
ncclResult_t nccl_net_ofi_iflush_v4(void* recvComm, void* data, int size, void* mhandle, void** request);
ncclResult_t nccl_net_ofi_closeSend(void *sendComm);
ncclResult_t nccl_net_ofi_closeRecv(void *recvComm);
ncclResult_t nccl_net_ofi_closeListen(void *listenComm);
ncclResult_t nccl_net_ofi_get_mr_key(void* mhandle, uint64_t* mr_key);
ncclResult_t nccl_net_ofi_iwrite(void* sComm, void* src, size_t size, void* mhandle,
				 uint64_t dest, uint64_t mr_key, void** req);
ncclResult_t nccl_net_ofi_iwrite_inline(void* sComm, void* src, size_t size,
					uint64_t dest, uint64_t mr_key, void** req);
ncclResult_t nccl_net_ofi_iread(void* rComm, void* dest, size_t size, void* mhandle,
				uint64_t src, uint64_t mr_key, void** req);

#endif // End NET_OFI_API_H_
