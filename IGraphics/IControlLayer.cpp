#include "IControlLayer.h"

int IControlLayer::AddControl(IControl * pControl){
  mControls.Add(pControl);
  return mControls.GetSize() - 1;
}

int IControlLayer::AddLayer(IControlLayer * pLayer) {
  mControlLayers.Add(pLayer);
  return mControlLayers.GetSize() - 1;
}

void IControlLayer::ForAllControlsFunc(std::function<void(IControl& control)> func) {
  for (int i = 0; i < mControls.GetSize(); i++){
    func(mControls.Get(i));
  }
  for (int i = 0; i < mControlLayers.GetSize(); i++){
    IControlLayer * pLayer = mControlLayers.Get(i);
    pLayer -> ForAllControlsFunc(func);
  }
}

void IControlLayer::Hide(bool hide){
  ForAllControlsFunc([&](IControl& control){
      control.Hide(hide)
  })
}

IControlLayer * IControlLayer::GetSubLayerByName(const char * layerName) {
  auto found = nullptr;
  for (int i = 0; i < mControlLayers.GetSize(); i++){
    IControlLayer * pControlLayer = mControlLayers.Get(i);
    if (CStringHasContents(pControlLayer-> GetName())){
      if (strcmp(pControlLayer-> GetName(), layerName) == 0){
        found = pControlLayer;
        break;
      }
    }
  }
  return found;
}


