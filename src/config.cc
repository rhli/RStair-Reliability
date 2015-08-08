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
    if(strcmp(ele->GetText(),"nodePerRack")==0){
      _nodePerRack=atoi(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"rackNum")==0){
      _rackNum=atoi(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"ecN")==0){
      _ecN=atoi(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"ecK")==0){
      _ecK=atoi(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"replicaNum")==0){
      _replicaNum=atoi(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"repPlaPolicy")==0){
      _repPlaPolicy=atoi(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"blockSize")==0){
      _blockSize=atoi(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"bandwidth")==0){
      _bandwidth=atof(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"writeInterval")==0){
      _writeInterval=atof(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"inClusWriteProportion")==0){
      _inClusWritePercent=atof(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"bgTrafficInterval")==0){
      _bgTrafficInterval=atof(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"inRackTrafficProportion")==0){
      _inRackTrafficPercent=atof(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"encodingStripeCount")==0){
      _encodingStripeCount=atof(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"randSeed")==0){
      _randSeed=atof(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"maxInRack")==0){
      _maxInRack=atof(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"stairRow")==0){
      _stairRow=atoi(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"stairColumn")==0){
      _stairColumn=atoi(ele->NextSiblingElement("value")->GetText());
    //}
    //else if(strcmp(ele->GetText(),"stairVectorLen")==0){
    //  _stairGlobalVecLen=atoi(ele->NextSiblingElement("value")->GetText());
    //  _stairGlobalVec = (int*)calloc(sizeof(int),_stairGlobalVecLen);
    }else if(strcmp(ele->GetText(),"stairVector")==0){
      //_maxInRack=atof(ele->NextSiblingElement("value")->GetText());
      char* stairGlobalVecString = (char*)calloc(sizeof(char),
          strlen(ele->NextSiblingElement("value")->GetText())+1);
      strcpy(stairGlobalVecString,ele->NextSiblingElement("value")->GetText());
      char* token = strtok(stairGlobalVecString,",");
      int index = 0;
      while(token!=NULL){
        token = strtok(NULL,",");
        index ++;
      }
      _stairGlobalVec=(int*)calloc(sizeof(int),index);
      strcpy(stairGlobalVecString,ele->NextSiblingElement("value")->GetText());
      token = strtok(stairGlobalVecString,",");
      for(int i=0;i<index;i++){
        _stairGlobalVec[i]=atoi(token);
        token = strtok(NULL,",");
      }
      free(stairGlobalVecString);
    }else if(strcmp(ele->GetText(),"codScheme")==0){
      if(strcmp(ele->NextSiblingElement("value")->GetText(),"stair")==0){
        _codScheme=STAIR;
      }else if(strcmp(ele->NextSiblingElement("value")->GetText(),"rs")==0){
        _codScheme=RS;
      }else if(strcmp(ele->NextSiblingElement("value")->GetText(),"lrc")==0){
        _codScheme=LRC;
      }else if(strcmp(ele->NextSiblingElement("value")->GetText(),"hcode")==0){
        _codScheme=HCODE;
      }else{
        fprintf(stderr,"Unrecognized coding scheme %s initialization failed\n",
            ele->NextSiblingElement("value")->GetText());
      }
    }else if(strcmp(ele->GetText(),"readInterval")==0){
      _readInterval=atof(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"RSK")==0){
      _rsK=atoi(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"HCODEK")==0){
      _hcodeK=atoi(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"LRCK")==0){
      _lrcK=atoi(ele->NextSiblingElement("value")->GetText());
    }else if(strcmp(ele->GetText(),"failedNode")==0){
      _failedNode=atoi(ele->NextSiblingElement("value")->GetText());
    }
  }
  _nodeNum=_rackNum*_nodePerRack;
}


