// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: ai.proto

#include "ai.pb.h"
#include "ai.grpc.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace rpc {

static const char* LonganRpc_method_names[] = {
  "/rpc.LonganRpc/FaceCheck",
  "/rpc.LonganRpc/FacesInfoBatchImports",
  "/rpc.LonganRpc/UpdateFacesInfo",
  "/rpc.LonganRpc/RegisterFace",
};

std::unique_ptr< LonganRpc::Stub> LonganRpc::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< LonganRpc::Stub> stub(new LonganRpc::Stub(channel));
  return stub;
}

LonganRpc::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_FaceCheck_(LonganRpc_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_FacesInfoBatchImports_(LonganRpc_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_UpdateFacesInfo_(LonganRpc_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_RegisterFace_(LonganRpc_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status LonganRpc::Stub::FaceCheck(::grpc::ClientContext* context, const ::rpc::PictureDataParam& request, ::rpc::CheckReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_FaceCheck_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::rpc::CheckReply>* LonganRpc::Stub::AsyncFaceCheckRaw(::grpc::ClientContext* context, const ::rpc::PictureDataParam& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rpc::CheckReply>::Create(channel_.get(), cq, rpcmethod_FaceCheck_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::rpc::CheckReply>* LonganRpc::Stub::PrepareAsyncFaceCheckRaw(::grpc::ClientContext* context, const ::rpc::PictureDataParam& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rpc::CheckReply>::Create(channel_.get(), cq, rpcmethod_FaceCheck_, context, request, false);
}

::grpc::Status LonganRpc::Stub::FacesInfoBatchImports(::grpc::ClientContext* context, const ::rpc::EmployeesParam& request, ::rpc::ImportReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_FacesInfoBatchImports_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::rpc::ImportReply>* LonganRpc::Stub::AsyncFacesInfoBatchImportsRaw(::grpc::ClientContext* context, const ::rpc::EmployeesParam& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rpc::ImportReply>::Create(channel_.get(), cq, rpcmethod_FacesInfoBatchImports_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::rpc::ImportReply>* LonganRpc::Stub::PrepareAsyncFacesInfoBatchImportsRaw(::grpc::ClientContext* context, const ::rpc::EmployeesParam& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rpc::ImportReply>::Create(channel_.get(), cq, rpcmethod_FacesInfoBatchImports_, context, request, false);
}

::grpc::Status LonganRpc::Stub::UpdateFacesInfo(::grpc::ClientContext* context, const ::rpc::EmployeesParam& request, ::rpc::ImportReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_UpdateFacesInfo_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::rpc::ImportReply>* LonganRpc::Stub::AsyncUpdateFacesInfoRaw(::grpc::ClientContext* context, const ::rpc::EmployeesParam& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rpc::ImportReply>::Create(channel_.get(), cq, rpcmethod_UpdateFacesInfo_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::rpc::ImportReply>* LonganRpc::Stub::PrepareAsyncUpdateFacesInfoRaw(::grpc::ClientContext* context, const ::rpc::EmployeesParam& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rpc::ImportReply>::Create(channel_.get(), cq, rpcmethod_UpdateFacesInfo_, context, request, false);
}

::grpc::Status LonganRpc::Stub::RegisterFace(::grpc::ClientContext* context, const ::rpc::RegParam& request, ::rpc::RegReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_RegisterFace_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::rpc::RegReply>* LonganRpc::Stub::AsyncRegisterFaceRaw(::grpc::ClientContext* context, const ::rpc::RegParam& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rpc::RegReply>::Create(channel_.get(), cq, rpcmethod_RegisterFace_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::rpc::RegReply>* LonganRpc::Stub::PrepareAsyncRegisterFaceRaw(::grpc::ClientContext* context, const ::rpc::RegParam& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::rpc::RegReply>::Create(channel_.get(), cq, rpcmethod_RegisterFace_, context, request, false);
}

LonganRpc::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LonganRpc_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LonganRpc::Service, ::rpc::PictureDataParam, ::rpc::CheckReply>(
          std::mem_fn(&LonganRpc::Service::FaceCheck), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LonganRpc_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LonganRpc::Service, ::rpc::EmployeesParam, ::rpc::ImportReply>(
          std::mem_fn(&LonganRpc::Service::FacesInfoBatchImports), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LonganRpc_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LonganRpc::Service, ::rpc::EmployeesParam, ::rpc::ImportReply>(
          std::mem_fn(&LonganRpc::Service::UpdateFacesInfo), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LonganRpc_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LonganRpc::Service, ::rpc::RegParam, ::rpc::RegReply>(
          std::mem_fn(&LonganRpc::Service::RegisterFace), this)));
}

LonganRpc::Service::~Service() {
}

::grpc::Status LonganRpc::Service::FaceCheck(::grpc::ServerContext* context, const ::rpc::PictureDataParam* request, ::rpc::CheckReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LonganRpc::Service::FacesInfoBatchImports(::grpc::ServerContext* context, const ::rpc::EmployeesParam* request, ::rpc::ImportReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LonganRpc::Service::UpdateFacesInfo(::grpc::ServerContext* context, const ::rpc::EmployeesParam* request, ::rpc::ImportReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LonganRpc::Service::RegisterFace(::grpc::ServerContext* context, const ::rpc::RegParam* request, ::rpc::RegReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace rpc

