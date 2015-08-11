#include <iostream>
#include <string>
#include <cstring>
#include <cstddef>
#include "config.hh"

using namespace tinyxml2;

config::config(){
  XMLDocument doc;
  doc.LoadFile("config/setting.xml");
  XMLElement* element;
  for(element = doc.FirstChildElement("sysSetting")->FirstChildElement("attribute");
      element!=NULL;
      element=element->NextSiblingElement("attribute")){
    XMLElement* ele = element->FirstChildElement("name");
    if(strcmp(ele->GetText(),"nodePerRack")==0)
      _nodePerRack=atoi(ele->NextSiblingElement("value")->GetText());
    else if(strcmp(ele->GetText(),"rackNum")==0)
      _rackNum=atoi(ele->NextSiblingElement("value")->GetText());
    else if(strcmp(ele->GetText(),"localRate")==0)
      _localRate=atof(ele->NextSiblingElement("value")->GetText());
    else if(strcmp(ele->GetText(),"globalRate")==0)
      _globalRate=atof(ele->NextSiblingElement("value")->GetText());
    else if(strcmp(ele->GetText(),"stairVec")==0){
      std::string vecStr=std::string(ele->NextSiblingElement("value")->GetText()); 
      int start=0,len=vecStr.length(),cpos;
      _stairVec.push_back(_nodePerRack);
      while((cpos=vecStr.find(",",start))!=std::string::npos){
        _stairVec.push_back(std::stoi(vecStr.substr(start,cpos-start+1))+1);
        start=cpos+1;
      }
      _stairVec.push_back(std::stoi(vecStr.substr(start,len-start))+1);
      for(int i=0;i<_rackNum;i++){
        _stairVec.push_back(1);
      }
      for(int i=0;i<_stairVec.size();i++) std::cout<<_stairVec[i]<<" ";
      std::cout<<std::endl;
    }
  }
  _nodeNum=_rackNum*_nodePerRack;
}


