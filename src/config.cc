#include <cstring>
#include "config.hh"

using namespace tinyxml2;

config::config(){
  XMLDocument doc;
  doc.LoadFile("config/sysSetting.xml");
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
  }
  _nodeNum=_rackNum*_nodePerRack;
}


