//
//  IControlLayer.h
//  jsonControls-macOS
//
//  Created by mk on 1/17/19.
//

#pragma once

#include "IControl.h"
#include "wdlstring.h"
#include "ptrlist.h"

class IControlLayer {
private:
  const char * name;
  WDL_PtrList<IControl> mControls;
  WDL_PtrList<IControlLayer> mControlLayers;
  
public:
  IControlLayer(const char * layerName){
    name = layerName;
  }
  
  int AddControl(IControl * pControl);
  int AddLayer(IControlLayer * pPlayer);
  const char * GetName() { return name; }
  void ForAllControlsFunc(std::function<void(IControl& control)> func);
  IControlLayer * GetSubLayerByName(const char * layerName);
  void Hide(bool hide);
};
