#include "JadeReader.hh"
#include "JadeUtils.hh"
#include "JadeFactory.hh"

#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <thread>

using _base_c_ = JadeReader;
using _index_c_ = JadeReader;

template class DLLEXPORT JadeFactory<_base_c_>;
template DLLEXPORT
std::unordered_map<std::type_index, typename JadeFactory<_base_c_>::UP (*)(const JadeOption&)>&
JadeFactory<_base_c_>::Instance<const JadeOption&>();

namespace{
  auto _loading_index_ = JadeUtils::SetTypeIndex(std::type_index(typeid(_index_c_)));
  auto _loading_ = JadeFactory<_base_c_>::Register<_index_c_, const JadeOption&>(typeid(_index_c_));
}


JadeReader::JadeReader(const JadeOption& opt){
}

JadeReader::~JadeReader(){
}

JadeReaderSP JadeReader::Make(const std::string& name, const JadeOption& opt){  
  try{
    std::cout << "JadeReader name: " << name << std::endl;
    std::type_index index = JadeUtils::GetTypeIndex(name);
    JadeReaderSP wrt =  JadeFactory<JadeReader>::MakeUnique<const JadeOption&>(index, opt);
    return wrt;
  }
  catch(...){
    std::cout<<"TODO: JadeReader"<<std::endl;
    return nullptr;
  }
}

JadeDataFrameSP JadeReader::Read(const std::chrono::milliseconds &timeout){
  std::this_thread::sleep_for(timeout);
  return nullptr;
}
