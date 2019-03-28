pipeline {
    agent {
        // 此处设定构建环境，目前可选有
        // default, java-8, python-3.5, ruby-2.3, go-1.11 等
        // 详情请阅 https://dev.tencent.com/help/knowledge-base/how-to-use-ci#agents
        label "default"
    }
    stages  {


        stage("推送") {
            steps {
                echo "推送中..."
                // 请在这里放置您项目代码的单元测试调用过程，例如:
                // sh 'mvn package' // mvn 示例
                // sh 'make' // make 示例
              sh 'git clone https://dt_RBcvZIN:47TOs7IXCszgRmPBfZqogtmrNzbASu@git.dev.tencent.com/cjsoft/HomeWork.git'
              dir ("HomeWork") {
                
               		 sh 'echo ${GHTK}'
                  sh 'git push --force "https://${GHTK}@github.com/cjsoft/HomeWork.git" master:master'
              }
                echo "推送完成."
              
                // 演示怎样产生构建物
                
              
                // archiveArtifacts artifacts: '**/target/*.jar', fingerprint: true // 收集构建产物
            }
        }

        
    }
}