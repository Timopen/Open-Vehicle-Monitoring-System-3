exports.format=function(r,t){var e="",a=null===r?"null":typeof r;"object"==a&&Array.isArray(r)&&(a="array");var n=!1!==t;switch(t||(t=""),a){case"string":e+='"'+r.replace(/\"/g,'\\"')+'"';break;case"array":e+=n?"[\n":"[";for(var o=0;o<r.length;o++)n&&(e+=t+"  "),e+=exports.format(r[o],!!n&&t+"  "),o!=r.length-1&&(e+=","),n&&(e+="\n");e+=t+"]";break;case"object":e+=n?"{\n":"{";var s=Object.keys(r);for(o=0;o<s.length;o++)e+=n?t+'  "'+s[o]+'": ':'"'+s[o]+'":',e+=exports.format(r[s[o]],!!n&&t+"  "),o!=s.length-1&&(e+=","),n&&(e+="\n");e+=t+"}";break;default:e+=""+r}return n&&""==t&&(e+="\n"),e},exports.print=function(r,t){print(exports.format(r,t))};
