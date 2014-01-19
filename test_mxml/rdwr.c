#include "/home/dhlinux/mxml-2.7pc/mxml.h"

double get_temperature() {
    return 23.1;
}

char *get_temperature_xml() {
    mxml_node_t *xml;
    mxml_node_t *data;
    mxml_node_t *node;
    
    char buffer[1024];

    xml = mxmlNewXML("1.0");
    data = mxmlNewElement(xml, "data");
    node = mxmlNewElement(data, "temperature");
    
    double temperature_data = get_temperature();
    mxmlNewReal(node, temperature_data);

    mxmlSaveString(xml, buffer, sizeof(buffer), MXML_NO_CALLBACK);
    
    return buffer;
}

int main() {
    char *buffer = get_temperature_xml();
    mxml_node_t *xml2 = mxmlLoadString(NULL, buffer, MXML_REAL_CALLBACK);

    printf("Temperature = %lf\n", mxmlGetReal(mxmlFindElement(xml2, xml2, "temperature",  NULL, NULL, MXML_DESCEND)));

    return 0;
}
