Sogeti-MasterThesis-CrossPlatformMobileDevelopment
==================================================

Mobility is becoming increasingly important for many companies. The markets for mobile applications have been growing tremendously the last decade. It is therefore of great interest to reduce the costs of development and maintenance of mobile applications.  When developing native applications for multiple platforms some parts of the code will likely implement the same functionality. This functionality is then implemented in different programming languages, for different platforms. Functionalities that are typically the same on all platforms are network communication, data parsing and business logic. These functionalities can account for a large part of the code when developing large and complex applications. This code duplication could be avoided if common functionality could be extracted from the applications and put in a shared base. 

The aim of this project is to investigate possible solutions to the problem of code duplication in the case of a specific business application, developed for iOS and Android. It consists of a mobile client which performs some transformation of data acquired from a business system and presents it in the native UIs.  

The thesis first discusses the requirements, constraints and delimitations which are inferred from the application type and the company wishing to apply cross-platform development. It also maps existing cross-platform development methods for this type of application and investigates to which extent the different cross-platform development methods fulfill the requirements. Finally the most suitable method is used in a practical context.  

The objectives of this project are to provide the company with a recommendation of a method as well as a prototype proving the concept of this method.  This project is delimited to only investigating possible solutions for mobile business applications with native UIs.  

The conclusion of the project is that native C++ is the most suitable method for this type of application. It fulfills all requirements, but further research is needed regarding performance.

This repository contains the code for all prototypes developed during the project. First prototypes using different technologies, and also more specialized prototypes using NDK and C++.

In the C++/NDK prototypes the library [POCO](https://github.com/pocoproject/poco) is used for some of the functionality.




´Best Regards: David Karlsson, Anna Troedsson Almér.´



Key Words: Cross-Platform Development, Android, Native, iOS, Xamarin, Titanium, NDK


[![githalytics.com alpha](https://cruel-carlota.pagodabox.com/f22d3c07ed508ffa567d40bb11c21d15 "githalytics.com")](http://githalytics.com/devdavidkarlsson/Sogeti-MasterThesis-CrossPlatformMobileDevelopment)

[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/devdavidkarlsson/Sogeti-MasterThesis-CrossPlatformMobileDevelopment/trend.png)](https://bitdeli.com/free "Bitdeli Badge")
