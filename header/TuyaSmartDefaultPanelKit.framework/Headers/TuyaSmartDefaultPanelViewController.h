//
//  TuyaSmartDefaultPanelKit.h
//  TuyaSmartDefaultPanelKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#ifndef TuyaSmartDefaultPanelViewController_h
#define TuyaSmartDefaultPanelViewController_h

#import <UIKit/UIKit.h>
#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief This class is the default device control panel and supports all types of `Powered by Tuya` devices. This class is designed for production use.
///
/// This ViewController can be used for all types of `Powered by Tuya` devices.
/// During the development of a control panel, you can call ViewController to preview the device functions.
/// After the control panel is developed, you can still call ViewController as an `else` option.
///
/// You can select a specific device control panel based on the following code:
///
/// if ([deviceModel.productId isEqualToString:PID_A]) {
///     UIViewController *vc = [[MyViewControllerA alloc] initWithDeviceId:deviceModel.devId];
///     [self.navigationController pushViewController:vc animated:YES];
/// } else if ([deviceModel.productId isEqualToString:PID_B]) {
///     UIViewController *vc = [[MyViewControllerB alloc] initWithDeviceId:deviceModel.devId];
///     [self.navigationController pushViewController:vc animated:YES];
/// } else {
///     UIViewController *vc = [[TuyaSmartDefaultPanelViewController alloc] initWithDeviceId:deviceModel.devId];
///     [self.navigationController pushViewController:vc animated:YES];
/// }
///
@interface TuyaSmartDefaultPanelViewController : UIViewController

- (nullable instancetype)initWithDeviceId:(NSString *)devId;

/// The debugging mode. Default value: `NO`.
@property (nonatomic, assign) BOOL debugMode;

@end

NS_ASSUME_NONNULL_END

#endif /* TuyaSmartDefaultPanelViewController_h */
