#include <stdio.h>
#include <assert.h>
#define THRESHOLD 200

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius<THRESHOLD)
    {
      return 200;
    }
    else
    {
      return 500;
    }
}
float convertFarenheitToCelcius(float farenheit) {
    float celcius = convertFarenheitToCelcius(farenheit);
    return celcius;
}
void alertInCelcius(float farenheit) {
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(600);
    alertInCelcius(620);
    assert(alertFailureCount == 3);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
