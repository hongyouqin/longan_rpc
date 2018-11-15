#include <iostream>
#include <memory>
#include <string>
#include <stdio.h>
#include <thread>
#include <chrono>

#include <grpcpp/grpcpp.h>
#include "longan_proto/ai.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using grpc::CompletionQueue;

int fu_ReadFile(const char *path, char **raw_data, size_t *pSize)
{
    int res = 0;
    FILE *fp = 0;
    char *data_file = 0;
    size_t size = 0;

    fp = fopen(path, "rb");
    if (fp == nullptr)
    {
        res = -1;
        goto exit;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    data_file = (char *)malloc(sizeof(char) * size);
    if (data_file == nullptr)
    {
        res = -2;
        goto exit;
    }

    if (size != fread(data_file, sizeof(char), size, fp))
    {
        res = -3;
        goto exit;
    }

    *raw_data = data_file;
    data_file = nullptr;
exit:
    if (fp != nullptr)
    {
        fclose(fp);
    }

    if (data_file != nullptr)
    {
        free(data_file);
    }

    if (nullptr != pSize)
    {
        *pSize = size;
    }

    return res;
}

class AsyncLanganClient {
public:
    AsyncLanganClient(std::shared_ptr<Channel> channel)
        : stub_(rpc::LonganRpc::NewStub(channel)) {}   

    void RegFace() {
        ::rpc::RegParam param;

        param.set_name("大天天2");
        param.set_login_name("tyu");
        param.set_employee_id("256");
        param.set_user_id(1234);
        
        ::rpc::PictureDataParam *photo = new ::rpc::PictureDataParam();
        photo->set_photo_width(3744);
        photo->set_photo_height(5616);


        char *datas = nullptr;
        size_t size = 0;
        fu_ReadFile("/home/qinhy/workspace/longan_client_rpc/src/123.JPG", &datas, &size);
        photo->set_photo_datas(datas, size);
        param.set_allocated_photo(photo);

        AsyncClientCall* call = new AsyncClientCall;

        call->response_reader = stub_->PrepareAsyncRegisterFace(&call->context, param, &cq_);

        // StartCall initiates the RPC call
        call->response_reader->StartCall();

         // Request that, upon completion of the RPC, "reply" be updated with the
        // server's response; "status" with the indication of whether the operation
        // was successful. Tag the request with the memory address of the call object.
        call->response_reader->Finish(&call->reply, &call->status, (void*)call);
    }


    // Loop while listening for completed responses.
    // Prints out the response from the server.
    void AsyncCompleteRpc() {
        void* got_tag;
        bool ok = false;

        // Block until the next result is available in the completion queue "cq".
        while (cq_.Next(&got_tag, &ok)) {
            // The tag in this example is the memory location of the call object
            AsyncClientCall* call = static_cast<AsyncClientCall*>(got_tag);

            // Verify that the request was completed successfully. Note that "ok"
            // corresponds solely to the request for updates introduced by Finish().
            GPR_ASSERT(ok);

            if (call->status.ok())
                std::cout << "Greeter received: " << call->reply.is_success() << std::endl;
            else
                std::cout << "RPC failed" << std::endl;

            // Once we're complete, deallocate the call object.
            delete call;
        }
    }
private:
       // struct for keeping state and data information
    struct AsyncClientCall {
        // Container for the data we expect from the server.
        ::rpc::RegReply reply;
        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // Storage for the status of the RPC upon completion.
        Status status;


        std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::rpc::RegReply>> response_reader;
    };

    std::unique_ptr<rpc::LonganRpc::Stub> stub_;
    
    CompletionQueue cq_;
};


class LanganClient
{
  public:
    LanganClient(std::shared_ptr<Channel> channel)
        : stub_(rpc::LonganRpc::NewStub(channel)) {}

    bool AiFaceCheck()
    {
        // char *datas = nullptr;
        // size_t size = 0;
        // fu_ReadFile("/home/qinhy/workspace/longan_client_rpc/src/camera.jpg", &datas, &size);
        // ::rpc::PictureDataParam param;
        // ::std::string data;
        // for (int index = 0; index < size; ++index) {
        //     data = datas[index];
        //     param.add_datas(data);
        // }
        // param.set_width(1280);
        // param.set_height(720);
        // param.set_format(0x201);

        // ::rpc::CheckReply reply;

        // ClientContext context;
        // Status status = stub_->FaceCheck(&context, param, &reply);
        // if (status.ok())
        // {
        //     return reply.is_face();
        // }
        // else
        // {
        //     std::cout << status.error_code() << ": " << status.error_message()
        //               << std::endl;
        // }

        return true;
    }

    bool FacesImports() {
        ClientContext context;
        ::rpc::EmployeesParam param;
         ::rpc::ImportReply reply;
        Status status = stub_->FacesInfoBatchImports(&context, param, &reply);
        if (status.ok()) {
            std::cout << "导入成功" << std::endl;
        }
        return true;
    }

    bool RegFace() {
        ClientContext context;
        ::rpc::RegParam param;


        param.set_name("宣洋洋");
        param.set_login_name("tyu");
        param.set_employee_id("256");
        param.set_user_id(1234);
        
        ::rpc::PictureDataParam *photo = new ::rpc::PictureDataParam();
        photo->set_photo_width(3550);
        photo->set_photo_height(5324);


        char *datas = nullptr;
        size_t size = 0;
        fu_ReadFile("/home/qinhy/workspace/longan_client_rpc/src/123.jpg", &datas, &size);

        // param.set_name("zhangsan254");
        // param.set_login_name("zzzz");
        // param.set_employee_id("3566");
        // param.set_user_id(1234);
        
        // ::rpc::PictureDataParam *photo = new ::rpc::PictureDataParam();
        // photo->set_photo_width(240);
        // photo->set_photo_height(300);
        // photo->set_photo_url("http://bbc/qin/123.jpg");

        // char *datas = nullptr;
        // size_t size = 0;
        // fu_ReadFile("/home/qinhy/workspace/longan_client_rpc/src/yuanlj_01.jpg", &datas, &size);
        photo->set_photo_datas(datas, size);
        param.set_allocated_photo(photo);

        ::rpc::RegReply reply;
        Status status = stub_->RegisterFace(&context, param, &reply);
        if (status.ok()) {
            bool res = reply.is_success();
            std::cout << "注册成功, 返回值： " << res << std::endl;
        } else {
            std::string error = status.error_message();
            std::cout << error.c_str() << std::endl;
        }
        //free(datas);
        return true;
    }

  private:
    std::unique_ptr<rpc::LonganRpc::Stub> stub_;
};

//std::thread thds[10];

int main(int argc, char **argv)
{
    // Instantiate the client. It requires a channel, out of which the actual RPCs
    // are created. This channel models a connection to an endpoint (in this case,
    // localhost at port 50051). We indicate that the channel isn't authenticated
    // (use of InsecureChannelCredentials()).


    // LanganClient langan2(grpc::CreateChannel(
    //      "192.168.90.88:50002", grpc::InsecureChannelCredentials()));
    //      langan2.RegFace();

    AsyncLanganClient langan(grpc::CreateChannel(
        "localhost:50002", grpc::InsecureChannelCredentials()));
    std::thread thread_ = std::thread(&AsyncLanganClient::AsyncCompleteRpc, &langan);
    // for (int index = 0; index < 10; index++) {
    //     std::cout << "注册" << index+1 << std::endl;
    //     langan.RegFace();
    // }

    langan.RegFace();
    thread_.join();  //blocks forever
    std::cout << "exit" << std::endl;
    return 0;
}
