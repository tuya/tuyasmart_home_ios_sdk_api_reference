//
//  TuyaSmartBLEWifiActivator+PlugPlay.h
//  TuyaSmartBLEKit
//
//  Created by 吴戈 on 2020/11/9.
//

#import <TuyaSmartBLEKit/TuyaSmartBLEKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBLEWifiActivator (PlugPlay)

/// Activate zigbee sub device with ble channel.
/// The result will callback by TuyaSmartBLEWifiActivatorDelegate.
///
/// @param advModel     Device advertisement model.
/// @param homeId       The Id for the current home.
/// @param device       Gateway device.
/// @param timeout      Timeout time.
- (void)activatorZigbeeSubDeviceWithBleChannel:(TYBLEAdvModel *)advModel
                                        homeId:(long long)homeId
                                 gatewayDevice:(TuyaSmartDevice *)device
                                       timeout:(NSTimeInterval)timeout;

/// Enabling zigbee sub device to switch to the zigbee distribution network.
///
/// @param advModel     Device advertisement model.
/// @param homeId       The Id for the current home.
/// @param success      This block will be called if success.
/// @param failure      This block will be called if some error occurred.
- (void)switchZigbeeSubDeviceToZigbeeActivator:(TYBLEAdvModel *)advModel
                                        homeId:(long long)homeId
                                       success:(TYSuccessHandler)success
                                       failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
