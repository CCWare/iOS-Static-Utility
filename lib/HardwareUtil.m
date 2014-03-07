//The MIT License (MIT)
//
//Copyright (c) 2013 CCWare
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of
//this software and associated documentation files (the "Software"), to deal in
//the Software without restriction, including without limitation the rights to
//use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//the Software, and to permit persons to whom the Software is furnished to do so,
//subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
//FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
//COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//  HardwareUtil.m
//  iOS Static Utility
//
//  Created by Michael on 2012/1/4.


#import "HardwareUtil.h"

@implementation HardwareUtil

+ (BOOL)hasRearCam
{
#if TARGET_IPHONE_SIMULATOR
    return NO;
#else
    return ([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera] &&
            [UIImagePickerController isCameraDeviceAvailable:UIImagePickerControllerCameraDeviceRear]);
#endif
}

+ (BOOL)canAutoFocus
{
#if TARGET_IPHONE_SIMULATOR
    return NO;
#else
    return [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo].isFocusPointOfInterestSupported;
#endif
}

+ (BOOL)hasTorch
{
#if TARGET_IPHONE_SIMULATOR
    return NO;
#else
    return [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo].hasTorch;
#endif
}

+ (AVCaptureTorchMode)torchMode
{
#if TARGET_IPHONE_SIMULATOR
    return NO;
#else
    return [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo].torchMode;
#endif
}

+ (BOOL)isTorching
{
#if TARGET_IPHONE_SIMULATOR
    return NO;
#else
    return ([HardwareUtil hasTorch] && [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo].torchLevel > 0.0);
#endif
}

+ (void)toggleTorch:(AVCaptureTorchMode)torchMode
{
#if !TARGET_IPHONE_SIMULATOR
    if([HardwareUtil hasTorch] &&
       [[AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo] isTorchModeSupported:torchMode])
    {
        [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo].torchMode = torchMode;
    }
#endif
}
@end
