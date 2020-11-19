#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include <iostream>

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::Storage;

namespace winrt::FamilyTree::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();

    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        StorageFolder localFolder = ApplicationData::Current().LocalFolder();
        std::cout << localFolder.DisplayName().c_str() << std::endl;
        myButton().Content(box_value(L"Clicked"));
    }
}
